#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Window;
class EventSystem;
class AssetManager;

class App
{
public:
	App();
	~App();
	void Run();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<EventSystem> m_eventSystem;
	AssetManager& m_assetManager;
	
	void Init();
	void RegisterForEvent();
	void Update();
	void Draw();

	void WindowCloseEventCallback();
};
