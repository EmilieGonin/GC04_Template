#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameObject;
class EventSystem;

class Scene : public sf::Drawable
{

public:
	Scene();

	// BACKGROUND
	void InstanciateBackground(const sf::Vector2f& windowSize);

	// BRICK
	void InstanciateBrick(int x, int y);
	void InstanciateLineBricks(const int count, const int maxWidth, const int posY = 0);
	void InstanciateColonBricks(const int countColon, const int countLine, const int maxWidth);

	// PADDLE
	void InstanciatePaddle(std::shared_ptr<EventSystem> eventSystem, int x, int y);

	void Update();
	void SetSize(const sf::Vector2f& ratioWindow);

private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::vector<std::shared_ptr<GameObject>> _gos;

protected:
	// Hérité via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};