#include "LevelManager.h"

#include "TextureHolder.h"

int **LevelManager::NextLevel(sf::VertexArray &r_va_level) {
    m_LevelSize.x = 0;
    m_LevelSize.y = 0;

    m_CurrentLevel++;
    if (m_CurrentLevel > NUM_LEVELS) {
        m_CurrentLevel = 1;
        m_TimeModifier -= .1f;
    }

    // Load the appropriate level from the text files
    std::string level_data_file;
    switch (m_CurrentLevel) {
    case 1:
        level_data_file = "levels/level1.txt";
        m_StartPosition.x = 100;
        m_StartPosition.y = 100;
        m_BaseTimeLimit = 30.0f;
        break;

    case 2:
        level_data_file = "levels/level2.txt";
        m_StartPosition.x = 100;
        m_StartPosition.y = 3600;
        m_BaseTimeLimit = 100.0f;
        break;

    case 3:
        level_data_file = "levels/level3.txt";
        m_StartPosition.x = 1250;
        m_StartPosition.y = 0;
        m_BaseTimeLimit = 30.0f;
        break;

    case 4:
        level_data_file = "levels/level4.txt";
        m_StartPosition.x = 50;
        m_StartPosition.y = 200;
        m_BaseTimeLimit = 50.0f;
        break;
    }

    std::ifstream input_file(level_data_file);
    std::string s;

    while (std::getline(input_file, s)) {
        ++m_LevelSize.y;
    }

    m_LevelSize.x = s.length();

    input_file.clear();
    input_file.seekg(0, std::ios::beg);

    int **array_level = new int *[m_LevelSize.y];
    for (int i = 0; i < m_LevelSize.y; i++) {
        array_level[i] = new int[m_LevelSize.x];
    }

    std::string row;
    int y = 0;
    while (input_file >> row) {
        for (int x = 0; x < row.length(); x++) {
            const char val = row[x];
            array_level[y][x] = atoi(&val);
        }
        y++;
    }

    input_file.close();

    r_va_level.setPrimitiveType(sf::Quads);
    r_va_level.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);
    int current_vertex = 0;

    for (int x = 0; x < m_LevelSize.x; x++) {
        for (int y = 0; y < m_LevelSize.y; y++) {
            r_va_level[current_vertex + 0].position =
                sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);

            r_va_level[current_vertex + 1].position =
                sf::Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);

            r_va_level[current_vertex + 2].position = sf::Vector2f(
                (x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

            r_va_level[current_vertex + 3].position =
                sf::Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

            // Which tile from the sprite sheet to use
            int vertical_offset = array_level[y][x] * TILE_SIZE;

            r_va_level[current_vertex + 0].texCoords =
                sf::Vector2f(0, 0 + vertical_offset);

            r_va_level[current_vertex + 1].texCoords =
                sf::Vector2f(TILE_SIZE, 0 + vertical_offset);

            r_va_level[current_vertex + 2].texCoords =
                sf::Vector2f(TILE_SIZE, TILE_SIZE + vertical_offset);

            r_va_level[current_vertex + 3].texCoords =
                sf::Vector2f(0, TILE_SIZE + vertical_offset);

            current_vertex += VERTS_IN_QUAD;
        }
    }

    return array_level;
}

sf::Vector2i LevelManager::GetLevelSize() { return m_LevelSize; }
int LevelManager::GetCurrentLevel() { return m_CurrentLevel; }
float LevelManager::GetTimeLimit() { return m_BaseTimeLimit * m_TimeModifier; }
sf::Vector2f LevelManager::GetStartPosition() { return m_StartPosition; }
