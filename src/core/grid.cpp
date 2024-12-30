#include "grid.h"

Grid::Grid(Vector2 pMapSize) :
    m_mapSize(pMapSize)
{
    for (int y = 0; y < m_mapSize.y / m_tileSize; y++)
    {
        for (int x = 0; x < m_mapSize.x / m_tileSize; x++)
        {
            m_mapTiles.emplace_back(new Tile(Vector2(x * m_tileSize, y * m_tileSize)));
        }
    }
}

void Grid::Draw(SDL_Renderer* pRen)
{
    // SDL_SetRenderDrawColor(pRen, 200, 200, 200, 50);

    // for (int y = 0; y < m_mapHeihgt / m_tileSize; y++)
    // {
    //     for (int x = 0; x < m_mapWidth / m_tileSize; x++)
    //     {
    //         SDL_FRect destR = {x * m_tileSize, y * m_tileSize, m_tileSize, m_tileSize};

    //         SDL_RenderRect(pRen, &destR);
    //     }
    // }

    for (auto& tile : m_mapTiles)
    {
        tile->Draw(pRen);
    }
}

void Grid::HandleMouse(const SDL_MouseMotionEvent& pEvent)
{
    for (auto& tile : m_mapTiles)
    {
        if (pEvent.x > tile->GetTilePosition().x && pEvent.x < tile->GetTilePosition().x + m_tileSize &&
            pEvent.y > tile->GetTilePosition().y && pEvent.y < tile->GetTilePosition().y + m_tileSize)
        {
            tile->SetTileHover(true);
        }
        else
        {
            tile->SetTileHover(false);
        }
    }
}

Grid::~Grid()
{
    for (auto& tile : m_mapTiles)
    {
        delete tile;
    }

    m_mapTiles.clear();
}