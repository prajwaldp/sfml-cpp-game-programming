#include "Engine.h"

bool Engine::DetectCollisions(PlayableCharacter &character) {
    bool reached_goal = false;
    sf::FloatRect detection_zone = character.GetPosition();

    // Make a FloatRect block to test each block
    sf::FloatRect block;

    block.width = TILE_SIZE;
    block.height = TILE_SIZE;

    int startx = (int)(detection_zone.left / TILE_SIZE) - 1;
    int starty = (int)(detection_zone.top / TILE_SIZE) - 1;
    int endx = (int)(detection_zone.left / TILE_SIZE) + 2;
    int endy = (int)(detection_zone.top / TILE_SIZE) + 3;

    if (startx < 0) {
        startx = 0;
    }

    if (starty < 0) {
        starty = 0;
    }

    sf::Vector2i level_size = m_LM.GetLevelSize();

    if (endx > level_size.x) {
        endx = level_size.x;
    }

    if (endy > level_size.y) {
        endy = level_size.y;
    }

    sf::FloatRect level(0, 0, level_size.x * TILE_SIZE,
                        level_size.y * TILE_SIZE);

    // If the character has fallen out of the map
    if (!character.GetPosition().intersects(level)) {
        // Respawn the character
        character.Spawn(m_LM.GetStartPosition(), GRAVITY);
    }

    for (int x = startx; x < endx; x++) {
        for (int y = starty; y < endy; y++) {
            block.left = x * TILE_SIZE;
            block.top = y * TILE_SIZE;

            if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {
                if (character.GetHead().intersects(block)) {
                    character.Spawn(m_LM.GetStartPosition(), GRAVITY);

                    if (m_ArrayLevel[y][x] == 2) {
                        m_SM.PlayFallInFire();
                    } else {
                        m_SM.PlayFallInWater();
                    }
                }
            }

            // If the character intersects with a regular block
            if (m_ArrayLevel[y][x] == 1) {
                if (character.GetRight().intersects(block)) {
                    character.StopRight(block.left);
                } else if (character.GetLeft().intersects(block)) {
                    character.StopLeft(block.left);
                }

                if (character.GetFeet().intersects(block)) {
                    character.StopFalling(block.top);
                } else if (character.GetHead().intersects(block)) {
                    character.StopJump();
                }
            }

            if (!m_PS.IsRunning()) {
                if (m_ArrayLevel[y][x] == 2 || m_ArrayLevel[y][x] == 3) {
                    if (character.GetFeet().intersects(block)) {
                        m_PS.EmitParticles(character.GetCenter());
                    }
                }
            }

            if (m_ArrayLevel[y][x] == 4) {
                reached_goal = true;
            }
        }
    }

    return reached_goal;
}
