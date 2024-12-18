#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameObject;

class Scene : public sf::Drawable
{

public:
	Scene();
	void Init(std::shared_ptr<sf::RenderWindow> window);
	void InitBackground();
	void Update();

private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::vector<std::shared_ptr<GameObject>> _gos;

protected:
	// Hérité via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};