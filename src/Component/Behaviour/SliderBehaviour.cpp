#pragma once

#include "SliderBehaviour.h"
#include "../../AssetManager.h"
#include "../../GameObject.h"
#include "../Draw/SpriteRenderer.h"
#include "../Collider/RectCollider.h"
#include "../Collider/CircleCollider.h"
#include "../Transform/TransformSFML.h"
#include "../../App.h"
#include "../../EventSystem.h"
 

using namespace std::placeholders;

SliderBehaviour::SliderBehaviour()
{
}

SliderBehaviour::~SliderBehaviour()
{
}

void SliderBehaviour::Update()
{
	m_direction = sf::Vector2f(0,0);
	if (m_movingLeft)
	{
		m_direction.x -= 1;
	}
	if (m_movingRight)
	{
		m_direction.x += 1;
	}
	if (m_movingTop)
	{
		m_direction.y -= 1;
	}
	if (m_movingBot)
	{
		m_direction.y += 1;
	}
	m_direction.x *= 3;
	m_direction.y *= 3;
	m_transform->move(m_direction);
}

void SliderBehaviour::Start()
{
	InitComponents();
}

void SliderBehaviour::InitComponents()
{
	m_transform = m_gameObject->GetComponent<TransformSFML>();
	
	m_transform->setPosition(sf::Vector2f(500,800));

	std::shared_ptr<SpriteRenderer> spriteRenderer = std::shared_ptr<SpriteRenderer>(new SpriteRenderer());
	m_gameObject->AddComponent(spriteRenderer);
	std::shared_ptr<sf::Texture> backgroundImage = AssetManager::GetInstance().GetTexture(TextureType::PADDLE);
	spriteRenderer->SetTexture(*backgroundImage);

	m_collider = std::make_shared<RectCollider>();
	m_collider->SetRectBounds(spriteRenderer->GetSprite()->getLocalBounds());
	m_gameObject->AddComponent(m_collider);

	m_direction = sf::Vector2f(0, 0);
	m_movingRight = false;
	m_movingLeft = false;
	m_movingTop = false;
	m_movingBot = false;

	auto pressBind = std::bind(&SliderBehaviour::InputKeyPressedCallBack, this, _1);
	App::GetInstance().m_eventSystem->KeyPressedEvent = pressBind;

	auto releaseBind = std::bind(&SliderBehaviour::InputKeyReleasedCallBack, this, _1);
	App::GetInstance().m_eventSystem->KeyReleasedEvent = releaseBind;

}

void SliderBehaviour::InputKeyPressedCallBack(const sf::Event::KeyPressed* input)
{
	if (input->scancode == sf::Keyboard::Scancode::A)
	{
		m_movingLeft = true;
	}
	if (input->scancode == sf::Keyboard::Scancode::D)
	{
		m_movingRight = true;
	}
	if (input->scancode == sf::Keyboard::Scancode::W)
	{
		m_movingTop = true;
	}
	if (input->scancode == sf::Keyboard::Scancode::S)
	{
		m_movingBot = true;
	}
}

void SliderBehaviour::InputKeyReleasedCallBack(const sf::Event::KeyReleased* input)
{
	if (input->scancode == sf::Keyboard::Scancode::A)
	{
		m_movingLeft = false;
	}
	if (input->scancode == sf::Keyboard::Scancode::D)
	{
		m_movingRight = false;
	}
	if (input->scancode == sf::Keyboard::Scancode::W)
	{
		m_movingTop = false;
	}
	if (input->scancode == sf::Keyboard::Scancode::S)
	{
		m_movingBot = false;
	}
}
