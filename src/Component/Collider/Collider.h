#pragma once
#include <functional>
#include <vector>
#include <memory>
#include "..\AComponent.h"

class Collider : public AComponent
{

public:
    void ManageCollision(std::shared_ptr<Collider> other);

    virtual bool CheckCollision(const Collider& other) = 0;
    virtual void Update() = 0;


    std::function<void(std::shared_ptr<Collider>)> OnCollisionStart;
    std::function<void(std::shared_ptr<Collider>)> OnCollisionUpdate;
    std::function<void(std::shared_ptr<Collider>)> OnCollisionEnd;
private:
    std::vector<std::shared_ptr<Collider>> m_currentCollisions;
    float m_radius;
};
