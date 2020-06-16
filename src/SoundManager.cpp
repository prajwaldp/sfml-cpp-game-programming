#include "SoundManager.h"

SoundManager::SoundManager() {
    m_FireBuffer.loadFromFile("sound/fire1.wav");
    m_FallInFireBuffer.loadFromFile("sound/fallinfire.wav");
    m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
    m_JumpBuffer.loadFromFile("sound/jump.wav");
    m_ReachedGoalBuffer.loadFromFile("sound/reachgoal.wav");

    m_Fire1Sound.setBuffer(m_FireBuffer);
    m_Fire2Sound.setBuffer(m_FireBuffer);
    m_Fire3Sound.setBuffer(m_FireBuffer);
    m_FallInFireSound.setBuffer(m_FallInFireBuffer);
    m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
    m_JumpSound.setBuffer(m_JumpBuffer);
    m_ReachedGoalSound.setBuffer(m_ReachedGoalBuffer);

    // When the player is 50 pixels away, sound is full volume
    float min_distance = 50;
    float attenuation_rate = 15;

    m_Fire1Sound.setAttenuation(attenuation_rate);
    m_Fire2Sound.setAttenuation(attenuation_rate);
    m_Fire3Sound.setAttenuation(attenuation_rate);

    m_Fire1Sound.setMinDistance(min_distance);
    m_Fire2Sound.setMinDistance(min_distance);
    m_Fire3Sound.setMinDistance(min_distance);

    m_Fire1Sound.setLoop(true);
    m_Fire2Sound.setLoop(true);
    m_Fire3Sound.setLoop(true);
}

void SoundManager::PlayFire(sf::Vector2f emitter_location,
                            sf::Vector2f listener_location) {
    sf::Listener::setPosition(listener_location.x, listener_location.y, 0.0f);

    switch (m_NextFireSound) {
    case 1:
        m_Fire1Sound.setPosition(emitter_location.x, emitter_location.y, 0.0f);
        if (m_Fire1Sound.getStatus() == sf::Sound::Status::Stopped) {
            m_Fire1Sound.play();
        }
        break;

    case 2:
        m_Fire2Sound.setPosition(emitter_location.x, emitter_location.y, 0.0f);
        if (m_Fire2Sound.getStatus() == sf::Sound::Status::Stopped) {
            m_Fire2Sound.play();
        }
        break;

    case 3:
        m_Fire3Sound.setPosition(emitter_location.x, emitter_location.y, 0.0f);
        if (m_Fire3Sound.getStatus() == sf::Sound::Status::Stopped) {
            m_Fire3Sound.play();
        }
        break;
    }

    m_NextFireSound++;
    if (m_NextFireSound > 3) {
        m_NextFireSound = 1;
    }
}

void SoundManager::PlayFallInFire() {
    m_FallInFireSound.setRelativeToListener(true);
    m_FallInFireSound.play();
}

void SoundManager::PlayFallInWater() {
    m_FallInWaterSound.setRelativeToListener(true);
    m_FallInWaterSound.play();
}

void SoundManager::PlayJump() {
    m_JumpSound.setRelativeToListener(true);
    m_JumpSound.play();
}

void SoundManager::PlayReachedGoal() {
    m_ReachedGoalSound.setRelativeToListener(true);
    m_ReachedGoalSound.play();
}
