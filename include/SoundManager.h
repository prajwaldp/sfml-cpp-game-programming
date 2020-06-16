#pragma once

#include <SFML/Audio.hpp>

class SoundManager {
  private:
    sf::SoundBuffer m_FireBuffer;
    sf::SoundBuffer m_FallInFireBuffer;
    sf::SoundBuffer m_FallInWaterBuffer;
    sf::SoundBuffer m_JumpBuffer;
    sf::SoundBuffer m_ReachedGoalBuffer;

    sf::Sound m_Fire1Sound;
    sf::Sound m_Fire2Sound;
    sf::Sound m_Fire3Sound;
    sf::Sound m_FallInFireSound;
    sf::Sound m_FallInWaterSound;
    sf::Sound m_JumpSound;
    sf::Sound m_ReachedGoalSound;

    int m_NextFireSound = 1;

  public:
    SoundManager();

    void PlayFire(sf::Vector2f, sf::Vector2f);
    void PlayFallInFire();
    void PlayFallInWater();
    void PlayJump();
    void PlayReachedGoal();
};
