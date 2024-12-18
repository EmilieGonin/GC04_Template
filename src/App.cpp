#pragma once

#include <iostream>

#include "App.h"
#include "AssetManager.h"
#include "Window.h"
#include "EventSystem.h"
#include "Scene.h"

using namespace std::placeholders;

App::App()
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
		while (const std::optional event = m_window->pollEvent())
		{
			m_eventSystem->ManageEvent(event);
		}
		Update();
		Draw();
	}
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
	m_scene->Init(std::shared_ptr<sf::RenderWindow>(m_window.get(), [](sf::RenderWindow*) {}));
	m_scene->InitBackground();
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
