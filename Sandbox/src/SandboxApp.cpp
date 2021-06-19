#include<Manifold.h>

class Sandbox : public Manifold::Application
{
public:
    Sandbox()
    {}
    ~Sandbox()
    {}
};

Manifold::Application* Manifold::CreateApplication()
{
    return new Sandbox();
}