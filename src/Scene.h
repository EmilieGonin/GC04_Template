#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class GameObject;

class Scene : public sf::Drawable
{

public:
	Scene();
	void InitBackground(const sf::Vector2f& windowSize);
	void Update();
	void SetSize(const sf::Vector2f& windowSize);

private:
	std::shared_ptr<sf::RenderWindow> m_window;
	std::vector<std::shared_ptr<GameObject>> _gos;

protected:
	// H�rit� via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};