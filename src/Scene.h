#include <vector>

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable
{

public:
	void Update();
private:
	std::vector<std::shared_ptr<GameObject>> _gos;
protected:
	// Hérité via Drawable
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};