#pragma once

namespace Manifold
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
        
    Manifold::Application* CreateApplication();
}