#include <vector>
#include <memory>
#include "Component/AComponent.h"

class GameObject 
{

public:
    void AddComponent(std::shared_ptr<AComponent> component);
    void RemoveComponent(std::shared_ptr<AComponent> component);
    void Update();

private:
    std::vector<std::shared_ptr<AComponent>> m_components;

};