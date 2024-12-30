#pragma once

#include <iostream>

#include <SDL3/SDL.h>


class App
{
public:
    App();
    ~App();
    
    void Run();
    
private:
    bool Init();

    void HandleInput();
    void Update();
    void Render();

private:
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;

    bool m_appRunning = false;

    class Grid* m_grid = nullptr;
};