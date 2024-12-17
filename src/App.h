#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Window;
class EventSystem;

class App
{
public:
	App();
	~App();
	void Run();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<EventSystem> m_eventSystem;

	
	void Init();
	void RegisterForEvent();
	void Update();
	void Draw();

	void WindowCloseEventCallback();
};
