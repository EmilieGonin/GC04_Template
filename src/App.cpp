#pragma once

#include <iostream>

#include "App.h"
#include "AssetManager.h"
#include "Window.h"
#include "EventSystem.h"
#include "AssetManager.h"
#include "Scene.h"

using namespace std::placeholders;

App::App() : m_assetManager(AssetManager::GetInstance())
{
}

App::~App()
{
}

void App::Run()
{
	Init();
	while (m_window->isOpen())
	{
		m_window->clear();

		// Resize All gameObject
		SetSize();

		while (const std::optional event = m_window->pollEvent())
		{
			m_eventSystem->ManageEvent(event);
		}
		Update();
		Draw();
	}
	m_window->close();
}

void App::Init()
{
	AssetManager::GetInstance().LoadAssets();

	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode({ 1600u, 900u }), "GC04_Template");
	m_eventSystem = std::shared_ptr<EventSystem>(new EventSystem());

	m_window->setFramerateLimit(144u);

	InitScene();

	RegisterForEvent();
}

void App::InitScene()
{
	m_scene = std::shared_ptr<Scene>(new Scene());
	m_scene->InstanciateBackground(m_window->getView().getSize());
	m_scene->InstanciateColonBricks(5, 10, m_window->getView().getSize().x);
}

void App::SetSize()
{
	float ratioX = (float)m_window->getView().getSize().x / (float)defaultWidth;
	float ratioY = (float)m_window->getView().getSize().y / (float)defaultHeight;

	m_scene->SetSize(sf::Vector2f(ratioX, ratioY));
}

void App::RegisterForEvent()
{
	auto closeWindowCallbackBind = std::bind(
		&App::WindowCloseEventCallback,
		this);
	m_eventSystem->WindowCloseEvent = closeWindowCallbackBind;
}

void App::Update()
{
	m_scene->Update();
}

void App::Draw()
{
	m_window->clear();
	m_window->draw(*m_scene);
	m_window->display();
}

void App::WindowCloseEventCallback()
{
	m_window->close();
}
