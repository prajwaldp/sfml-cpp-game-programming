#include "Engine.h"

void Engine::Input() {
    sf::Event event;
    while (m_Window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                m_Window.close();
            }

            if (event.key.code == sf::Keyboard::Return) {
                m_IsPlaying = true;
            }

            if (event.key.code == sf::Keyboard::S) {
                m_Character1 = !m_Character1;
            }

            if (event.key.code == sf::Keyboard::X) {
                m_SplitScreen = !m_SplitScreen;
            }
        }
    }

    if (m_Thomas.HandleInput()) {
        m_SM.PlayJump();
    }

    if (m_Bob.HandleInput()) {
        m_SM.PlayJump();
    }
}
