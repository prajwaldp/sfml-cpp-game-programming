#include "Engine.h"

void Engine::Update(float dtAsSeconds) {
    if (m_NewLevelRequired) {
        // m_Thomas.Spawn(sf::Vector2f(0, 0), GRAVITY);
        // m_Bob.Spawn(sf::Vector2f(100, 0), GRAVITY);

        // Make sure Spawn is called only once
        // m_TimeRemaining = 10;
        // m_NewLevelRequired = false;

        LoadLevel();
    }

    if (m_IsPlaying) {
        m_Thomas.Update(dtAsSeconds);
        m_Bob.Update(dtAsSeconds);

        if (DetectCollisions(m_Thomas) && DetectCollisions(m_Bob)) {
            m_NewLevelRequired = true;
            m_SM.PlayReachedGoal();
        } else {
            DetectCollisions(m_Bob);
        }

        if (m_Bob.GetFeet().intersects(m_Thomas.GetHead())) {
            m_Bob.StopFalling(m_Thomas.GetHead().top);
        } else if (m_Thomas.GetFeet().intersects(m_Bob.GetHead())) {
            m_Thomas.StopFalling(m_Bob.GetHead().top);
        }

        m_TimeRemaining -= dtAsSeconds;

        if (m_TimeRemaining <= 0) {
            m_NewLevelRequired = true;
        }
    }

    for (auto it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++) {
        float posx = (*it).x;
        float posy = (*it).y;

        // 500px zone
        sf::FloatRect local_rect(posx - 250, posy - 250, 500, 500);

        if (m_Thomas.GetPosition().intersects(local_rect)) {
            m_SM.PlayFire(sf::Vector2f(posx, posy), m_Thomas.GetCenter());
        }
    }

    if (m_SplitScreen) {
        m_LeftView.setCenter(m_Thomas.GetCenter());
        m_RightView.setCenter(m_Bob.GetCenter());
    } else {
        if (m_Character1) {
            m_MainView.setCenter(m_Thomas.GetCenter());
        } else {
            m_MainView.setCenter(m_Bob.GetCenter());
        }
    }

    m_FrameSinceLastHudUpdate++;
    if (m_FrameSinceLastHudUpdate > m_TargetFramesPerHudUpdate) {
        std::stringstream ss_time;
        std::stringstream ss_level;

        ss_time << (int)m_TimeRemaining;
        m_Hud.SetTime(ss_time.str());

        ss_level << "Level: " << m_LM.GetCurrentLevel();
        m_Hud.SetLevel(ss_level.str());

        m_FrameSinceLastHudUpdate = 0;
    }

    if (m_PS.IsRunning()) {
        m_PS.Update(dtAsSeconds);
    }
}
