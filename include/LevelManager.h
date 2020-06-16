#pragma once

#include <SFML/Graphics.hpp>

class LevelManager {
  private:
    sf::Vector2i m_LevelSize;
    sf::Vector2f m_StartPosition;
    float m_TimeModifier = 1;
    float m_BaseTimeLimit = 0;
    int m_CurrentLevel = 4;
    const int NUM_LEVELS = 4;

  public:
    const int TILE_SIZE = 50;
    const int VERTS_IN_QUAD = 4;

    float GetTimeLimit();
    sf::Vector2f GetStartPosition();
    int **NextLevel(sf::VertexArray &);
    sf::Vector2i GetLevelSize();
    int GetCurrentLevel();
};
