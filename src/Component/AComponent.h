
class AComponent 
{

public:

    virtual ~AComponent() = default;
    virtual void Update() = 0;
    virtual void Start();

private:
    bool m_isStarted;
};