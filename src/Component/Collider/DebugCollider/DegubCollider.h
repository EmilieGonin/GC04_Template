#include <memory>
#include <SFML/Graphics.hpp>
#include "../../Draw/DrawableSFML.h"

class TransformSFML;

class DebugCollider: public DrawableSFML
{
public:
	DebugCollider();
	~DebugCollider();

	virtual void Start() override;
	void SetShape(std::shared_ptr<sf::Shape> shape);
	std::shared_ptr<sf::Shape> GetShape();

private:
	std::shared_ptr<TransformSFML> m_transform;
	std::shared_ptr<sf::Shape> m_shape;
	// Hérité via DrawableSFML
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
