#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas() {
    m_Sprite = sf::Sprite(TextureHolder::GetTexture("graphics/thomas.png"));
    m_JumpDuration = .45;
}

bool Thomas::HandleInput() {
    m_JustJumped = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (!m_IsJumping && !m_IsFalling) {
            m_IsJumping = true;
            m_TimeThisJump = 0;
            m_JustJumped = true;
        }
    } else {
        m_IsJumping = false;
        m_IsFalling = true;
    }

    m_LeftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    m_RightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    return m_JustJumped;
}
