#pragma once

#include <SDL3/SDL.h>

#include "drawable.h"

#include "../utils/vector.h"

class Tile : public Drawable
{
public:
    Tile(Vector2 pPosition);
    ~Tile();

    void Draw(SDL_Renderer* pRen) override;

    Vector2 GetTilePosition() const { return m_position; };

    void SetTileHover(bool pHoverState) { m_hover = pHoverState; };

private:
    Vector2 m_position;

    float m_tileSize = 32.0f;

    bool m_hover = false;
    bool m_empty = true;
};