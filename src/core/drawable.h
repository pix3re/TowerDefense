#pragma once

#include <SDL3/SDL.h>

class Drawable
{
public:
    Drawable() {};
    virtual ~Drawable() = default;

    virtual void Draw(SDL_Renderer* pRen) = 0;
};