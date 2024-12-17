#include "EventSystem.h"

EventSystem::EventSystem()
{
}

EventSystem::~EventSystem()
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


}
