#pragma once

#include <optional>
#include <SFML/Window/Event.hpp>
#include <functional>
#include <vector>

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	std::function<void()> WindowCloseEvent; 
	std::vector<std::function<void(const sf::Event::KeyPressed&)>> KeyPressedCallbacks;
	std::vector<std::function<void(const sf::Event::KeyReleased&)>> KeyReleasedCallbacks;


	void Init();
	void ManageEvent(const std::optional<sf::Event> event) ;
	void SubscribeToKeyPressed(const std::function<void(const sf::Event::KeyPressed&)>& callback);
	void SubscribeToKeyReleased(const std::function<void(const sf::Event::KeyReleased&)>& callback);

private:

};
