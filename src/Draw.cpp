#include "Engine.h"

void Engine::Draw() {
    m_Window.clear(sf::Color::White);

    m_RippleShader.setUniform("uTime", (int)m_GameTimeTotal.asSeconds());

    if (!m_SplitScreen) {
        m_Window.setView(m_BGMainView);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_MainView);

        m_Window.draw(m_VALevel, &m_TextureTiles);

        m_Window.draw(m_Thomas.GetSprite());
        m_Window.draw(m_Bob.GetSprite());

        if (m_PS.IsRunning()) {
            m_Window.draw(m_PS);
        }
    } else {
        // Split-screen view is active

        m_Window.setView(m_BGLeftView);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_LeftView);

        m_Window.draw(m_VALevel, &m_TextureTiles);

        m_Window.draw(m_Bob.GetSprite());
        m_Window.draw(m_Thomas.GetSprite());

        if (m_PS.IsRunning()) {
            m_Window.draw(m_PS);
        }

        m_Window.setView(m_BGRightView);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_RightView);

        m_Window.draw(m_VALevel, &m_TextureTiles);

        m_Window.draw(m_Thomas.GetSprite());
        m_Window.draw(m_Bob.GetSprite());

        if (m_PS.IsRunning()) {
            m_Window.draw(m_PS);
        }
    }

    m_Window.setView(m_HudView);
    m_Window.draw(m_Hud.GetLevel());
    m_Window.draw(m_Hud.GetTime());
    if (!m_IsPlaying) {
        m_Window.draw(m_Hud.GetMessage());
    }

    m_Window.display();
}
