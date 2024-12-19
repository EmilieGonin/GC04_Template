#include <vector>
#include <memory>
#include "Collider/Collider.h"
#include "../Singleton.h"

class ColliderSystem : public Singleton<ColliderSystem>
{

public:
    void AddCollider(std::shared_ptr<Collider> collider);
    void CheckCollisions();

private:
    std::vector<std::shared_ptr<Collider>> m_colliders;

    friend class Singleton<ColliderSystem>;

};

