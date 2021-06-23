#pragma once

extern Manifold::Application* Manifold::CreateApplication();

int main(int argc, char** argv)
{
    Manifold::Log::Init();
    MF_CORE_WARN("Initialized Log");
    MF_INFO("Hello");

    printf("Welcome to Manifold Game Engine\n");
    auto app = Manifold::CreateApplication();
    app->Run();
    delete app;
}