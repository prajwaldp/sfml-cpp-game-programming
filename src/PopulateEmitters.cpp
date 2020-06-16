#include "Engine.h"

void Engine::PopulateEmitters(std::vector<sf::Vector2f> &v_sound_emitters,
                              int **array_level) {

    v_sound_emitters.empty();

    sf::FloatRect previous_emitter;

    for (int x = 0; x < (int)m_LM.GetLevelSize().x; x++) {
        for (int y = 0; y < (int)m_LM.GetLevelSize().y; y++) {
            if (array_level[y][x] == 2) {
                if (!sf::FloatRect(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
                                   TILE_SIZE)
                         .intersects(previous_emitter)) {

                    v_sound_emitters.push_back(
                        sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE));

                    // Make a block of 300x300px block
                    // To make no further emitters in
                    previous_emitter.left = x * TILE_SIZE;
                    previous_emitter.top = y * TILE_SIZE;
                    previous_emitter.width = TILE_SIZE * 6;
                    previous_emitter.height = TILE_SIZE * 6;
                }
            }
        }
    }
    return;
}
