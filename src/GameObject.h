#include <vector>
#include <memory>
#include "Component/AComponent.h"

class GameObject 
{

public:
    void addComponent(std::shared_ptr<AComponent> component);
    void update();

private:
    std::vector<std::shared_ptr<AComponent>> components;

};