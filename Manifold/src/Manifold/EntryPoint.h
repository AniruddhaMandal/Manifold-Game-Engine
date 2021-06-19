#pragma once

extern Manifold::Application* Manifold::CreateApplication();

int main(int argc, char** argv)
{
    printf("Welcome to Manifold Game Engine\n");
    auto app = Manifold::CreateApplication();
    app->Run();
    delete app;
}