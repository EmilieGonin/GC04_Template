#include <vector>
#include <memory>
#include "Collider/Collider.h"

class ColliderSystem 
{

public:
    void AddCollider(std::shared_ptr<Collider> collider);
    void CheckCollisions();

private:
    std::vector<std::shared_ptr<Collider>> m_colliders;

};

