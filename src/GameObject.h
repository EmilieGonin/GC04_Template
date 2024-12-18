#include <vector>
#include <memory>
#include "Component/AComponent.h"

class GameObject 
{

public:
    void AddComponent(std::shared_ptr<AComponent> component);
    void RemoveComponent(std::shared_ptr<AComponent> component);
    void Update();

    template<typename T>
    std::shared_ptr<T> GetComponent();
private:
    void Start();
    std::vector<std::shared_ptr<AComponent>> m_components;
    bool m_isStarted;

};

template<typename T>
inline std::shared_ptr<T> GameObject::GetComponent()
{
    for (auto component : m_components)
    {
        auto componentCasted = std::dynamic_pointer_cast<T>(component);
        if (componentCasted)
        {
            return componentCasted;
        }
    }
    return nullptr;
}
