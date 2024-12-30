#include "app.h"

#include "grid.h"

App::App()
{
    if (Init())
    {
        m_appRunning = true;

        m_grid = new Grid(Vector2(800.0f, 576.0f));
    }
}

bool App::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "[APP]::Failed to init SDL.\n" << SDL_GetError() << std::endl;
        return false;
    }

    if (!SDL_CreateWindowAndRenderer("Tower Defenese", 800, 576, SDL_WINDOW_RESIZABLE, &m_window, &m_renderer))
    {
        std::cerr << "[APP]::Failed to create window and renderer.\n" << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);

    return true;
}

void App::Run()
{
    while(m_appRunning)
    {
        HandleInput();
        Update();
        Render();
    }
}

void App::HandleInput()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_EVENT_QUIT:
            m_appRunning = false;
            break;
        
        case SDL_EVENT_KEY_DOWN:
            if (e.key.scancode == SDL_SCANCODE_ESCAPE) m_appRunning = false;

            break;

        case SDL_EVENT_MOUSE_MOTION:
            m_grid->HandleMouse(e.motion);
            break;
        }
    }
}

void App::Update()
{
    // update entity list
}

void App::Render()
{
    SDL_SetRenderDrawColor(m_renderer, 25, 25, 25, 1);
    SDL_RenderClear(m_renderer); 

    // render all entities
    m_grid->Draw(m_renderer);

    SDL_RenderPresent(m_renderer);
}

App::~App()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}