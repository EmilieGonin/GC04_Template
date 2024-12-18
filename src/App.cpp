#include <iostream>

#include "App.h"
#include "Window.h"
#include "EventSystem.h"
#include "AssetManager.h"

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
	std::cout << "App created" << std::endl;
	m_window->setFramerateLimit(144u);

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
}

void App::Draw()
{
	m_window->clear();
	m_window->display();
}

void App::WindowCloseEventCallback()
{
	m_window->close();
}
