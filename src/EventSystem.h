#include <optional>
#include <SFML/Window/Event.hpp>
#include <functional>

class EventSystem
{
public:
	EventSystem();
	~EventSystem();

	std::function<void()> WindowCloseEvent;

	void Init();
	void ManageEvent(const std::optional<sf::Event> event) ;

private:

};
