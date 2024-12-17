#include <vector>
#include <memory>
#include "Collider/Collider.h"

class ColliderSystem 
{

public:
    void addCollider(std::shared_ptr<Collider> collider);
    void checkCollisions();

private:
    std::vector<std::shared_ptr<Collider>> colliders;

};

