#pragma once

#include <vector>

#include <SDL3/SDL.h>

#include "drawable.h"
#include "tile.h"

#include "../utils/vector.h"


class Grid : public Drawable
{

public:
    Grid(Vector2 pMapSize);
    ~Grid();

    void Draw(SDL_Renderer* pRen) override;

    void HandleMouse(const SDL_MouseMotionEvent& pEvent);

private:
    float m_tileSize = 32.0f;

    Vector2 m_mapSize;

    std::vector<Tile*> m_mapTiles;
};