#include <memory>
#include <SFML/Graphics.hpp>

class Window;
class EventSystem;
class AssetManager;
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
	AssetManager& m_assetManager;
	std::shared_ptr<Scene> m_scene;

	unsigned int defaultWidth = 1600u;
	unsigned int defaultHeight = 900u;
	
	void Init();
	void InitScene();
	void SetSize();
	void RegisterForEvent();
	void Update();
	void Draw();

	void WindowCloseEventCallback();
};
