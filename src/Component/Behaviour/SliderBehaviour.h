#pragma once
#include "../AComponent.h"

class TransformSFML;
class RectCollider;
class Collider;

class SliderBehaviour : public AComponent
{
public:
	SliderBehaviour();
	~SliderBehaviour();

	// Hérité via AComponent
	virtual void Update() override;
	virtual void Start() override;
private:

	void InitComponents();
	void InputKeyPressedCallBack(const sf::Event::KeyPressed*);
	void InputKeyReleasedCallBack(const sf::Event::KeyReleased*);
	void StartCollideCallBack(std::shared_ptr<Collider> other);
	void EndCollideCallBack(std::shared_ptr<Collider> other);

	sf::Vector2f m_direction;
	bool m_movingRight;
	bool m_movingLeft;
	bool m_movingTop;
	bool m_movingBot;


	std::shared_ptr<TransformSFML> m_transform;
	std::shared_ptr<RectCollider> m_collider;
};
