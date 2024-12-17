#include <iostream>

#include "App.h"
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
	m_window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow());
	m_eventSystem = std::shared_ptr<EventSystem>(new EventSystem());

	m_window->create(sf::VideoMode({ 1600u, 900u }), "GC04_Template");
	m_window->setFramerateLimit(144u);

	m_scene = std::shared_ptr<Scene>(new Scene());

	RegisterForEvent();
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
