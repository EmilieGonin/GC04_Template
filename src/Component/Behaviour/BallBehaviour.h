#include "../AComponent.h"

class TransformSFML;
class Collider;
class CircleCollider;

class BallBehaviour : public AComponent
{
public:
	BallBehaviour();
	~BallBehaviour();

	// Hérité via AComponent
	virtual void Update() override;
	virtual void Start() override;

	void SetDirection(sf::Vector2f newDir);

private:
	
	void CollisionStartCallback(std::shared_ptr<Collider> other);

	std::shared_ptr<TransformSFML> m_transform;
	std::shared_ptr<CircleCollider> m_collider;

	sf::Vector2f m_direction;
};

