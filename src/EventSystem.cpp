#pragma once

#include "EventSystem.h"

EventSystem::EventSystem()
{

}

EventSystem::~EventSystem()
{

}

void EventSystem::Init()
{

}

void EventSystem::ManageEvent(const std::optional<sf::Event> event)
{
    if (event->is<sf::Event::Closed>())
    {
        if (WindowCloseEvent)
        {
            WindowCloseEvent();
        }
    }
    if (event->is<sf::Event::KeyPressed>())
    {
        auto keypressedEvent = event->getIf<sf::Event::KeyPressed>(); 
        if (KeyPressedEvent)
        {
            KeyPressedEvent(keypressedEvent);
        }
    }
    if (event->is<sf::Event::KeyReleased>())
    {
        auto keyReleasedEvent = event->getIf<sf::Event::KeyReleased>();
        if (KeyReleasedEvent)
        {
            KeyReleasedEvent(keyReleasedEvent);
        }
    }
}
