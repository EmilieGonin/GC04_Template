#include <optional>
#include <SFML/Window/Event.hpp>
#include <functional>

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	std::function<void()> WindowCloseEvent;
	std::function<void(const sf::Event::KeyPressed*)> KeyPressedEvent;
	std::function<void(const sf::Event::KeyReleased*)> KeyReleasedEvent;

	void Init();
	void ManageEvent(const std::optional<sf::Event> event) ;

private:

};
