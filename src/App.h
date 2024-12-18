#include <memory>
#include <SFML/Graphics.hpp>

class Window;
class EventSystem;
class Scene;

class App
{
public:
	App();
	~App();
	void Run();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	std::shared_ptr<EventSystem> m_eventSystem;
	std::shared_ptr<Scene> m_scene;
	
	void Init();
	void InitScene();
	void RegisterForEvent();
	void Update();
	void Draw();

	void WindowCloseEventCallback();
};
