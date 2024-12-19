#include "PaddleBehaviour.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"
#include "../Transform/ATransform.h"
#include <memory>

PaddleBehaviour::PaddleBehaviour() :
	m_speed(0)
{

}

void PaddleBehaviour::Init(std::shared_ptr<EventSystem> eventSystem)
{
	std::shared_ptr<ATransform> transform = m_gameObject->GetComponent<ATransform>();

	// SPRITE
	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);

	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::PADDLE);
	spriteRenderer->SetTexture(*backgroundImage);

	transform->m_width = backgroundImage->getSize().x;
	transform->m_height = backgroundImage->getSize().y;

	// RECT COLLIDER

	std::shared_ptr<RectCollider> rectCollider = std::shared_ptr<RectCollider>(new RectCollider());
	m_gameObject->AddComponent(rectCollider);

	// EVENTS

	eventSystem->SubscribeToKeyPressed([this](const sf::Event::KeyPressed& event) {
		if (event.code == sf::Keyboard::Key::Left) {
			this->Move(-1);
		}
		});

	eventSystem->SubscribeToKeyPressed([this](const sf::Event::KeyPressed& event) {
		if (event.code == sf::Keyboard::Key::Right) {
			this->Move(1);
		}
		});

	// SPEED

	m_speed = 5;
}

void PaddleBehaviour::Update()
{

}

void PaddleBehaviour::Move(int value)
{
	std::shared_ptr<ATransform> transform = m_gameObject->GetComponent<ATransform>();
	transform->SetPosition(transform->GetPositionX() + (value * m_speed), transform->GetPositionY());
}
