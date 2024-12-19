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

    if (event->is<sf::Event::KeyPressed>()) {
        auto keyPressedEvent = event->getIf<sf::Event::KeyPressed>();
        for (auto& callback : KeyPressedCallbacks) {
            callback(*keyPressedEvent);
        }
    }

    if (event->is<sf::Event::KeyReleased>()) {
        auto keyReleasedEvent = event->getIf<sf::Event::KeyReleased>();
        for (auto& callback : KeyReleasedCallbacks) {
            callback(*keyReleasedEvent);
        }
    }
}

void EventSystem::SubscribeToKeyPressed(const std::function<void(const sf::Event::KeyPressed&)>& callback) {
    KeyPressedCallbacks.push_back(callback);
}

void EventSystem::SubscribeToKeyReleased(const std::function<void(const sf::Event::KeyReleased&)>& callback) {
    KeyReleasedCallbacks.push_back(callback);
}
