#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class GameObject;

class AComponent 
{

public:

    virtual ~AComponent() = default;
    virtual void Update() = 0;
    virtual void Start();
    virtual void Init(std::shared_ptr<GameObject> gameObject);

private:
    bool m_isStarted;

protected:
    std::shared_ptr<GameObject> m_gameObject;
};