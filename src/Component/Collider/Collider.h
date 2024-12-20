#pragma once
#include <functional>
#include <vector>
#include <memory>
#include "..\AComponent.h"

class TransformSFML;

class Collider : public AComponent, public std::enable_shared_from_this<Collider>
{

public:
    void ManageCollision(std::shared_ptr<Collider> other);

    virtual bool CheckCollision(std::shared_ptr<Collider> other) = 0;
    virtual void Update() = 0;
    virtual void Start() override;

    bool m_isActive;
    std::shared_ptr<TransformSFML> GetTransform();

    std::function<void(std::shared_ptr<Collider>)> OnCollisionStart;
    std::function<void(std::shared_ptr<Collider>)> OnCollisionUpdate;
    std::function<void(std::shared_ptr<Collider>)> OnCollisionEnd;
private:
    std::vector<std::shared_ptr<Collider>> m_currentCollisions;
    float m_radius;

protected:

#ifdef ENABLE_DEBUG_MACRO
    virtual void InitDebugComponent() = 0;
public:
    virtual void EnabledDebugComponent(bool active) = 0;
#endif
protected:

    std::shared_ptr<TransformSFML> m_transform;

};
