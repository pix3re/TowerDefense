#include "tile.h"

Tile::Tile(Vector2 pPosition) :
    Drawable(), m_position(pPosition)
{

}

void Tile::Draw(SDL_Renderer* pRen)
{
    SDL_SetRenderDrawColor(pRen, 200, 200, 200, 50);

    SDL_FRect destR = {m_position.x, m_position.y, m_tileSize, m_tileSize};

    if (m_hover)
    {
        SDL_RenderFillRect(pRen, &destR);
    }
    else
    {
        SDL_RenderRect(pRen, &destR);
    }
}

Tile::~Tile()
{

}