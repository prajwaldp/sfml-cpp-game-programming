#include "PlayableCharacter.h"

void PlayableCharacter::Spawn(sf::Vector2f start_position, float gravity) {
    m_Position.x = start_position.x;
    m_Position.y = start_position.y;
    m_Gravity = gravity;
    m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::Update(float elapsed_time) {
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsed_time;
    }

    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsed_time;
    }

    if (m_IsJumping) {
        m_TimeThisJump += elapsed_time;

        // If the jump is going upwards
        if (m_TimeThisJump < m_JumpDuration) {
            // Move up at twice the gravity
            m_Position.y -= m_Gravity * 2 * elapsed_time;
        } else {
            m_IsJumping = false;
            m_IsFalling = true;
        }
    }

    if (m_IsFalling) {
        m_Position.y += m_Gravity * elapsed_time;
    }

    // Update the rect for all body parts
    sf::FloatRect r = GetPosition();

    // Feet
    m_Feet.left = r.left + 3;
    m_Feet.top = r.top + r.height - 1;
    m_Feet.width = r.width - 6;
    m_Feet.height = 1;

    // Head
    m_Head.left = r.left;
    m_Head.top = r.top + (r.height * .3);
    m_Head.width = r.width;
    m_Head.height = 1;

    // Right
    m_Right.left = r.left + r.width - 2;
    m_Right.top = r.top + r.height * .35;
    m_Right.width = 1;
    m_Right.height = r.height * .3;

    // Left
    m_Left.left = r.left;
    m_Left.top = r.top + r.height * .5;
    m_Left.width = 1;
    m_Left.height = r.height * .3;

    // Move the sprite into position
    m_Sprite.setPosition(m_Position);
}

sf::FloatRect PlayableCharacter::GetPosition() {
    return m_Sprite.getGlobalBounds();
}

sf::Vector2f PlayableCharacter::GetCenter() {
    return sf::Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width / 2,
                        m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

sf::FloatRect PlayableCharacter::GetFeet() { return m_Feet; }
sf::FloatRect PlayableCharacter::GetHead() { return m_Head; }
sf::FloatRect PlayableCharacter::GetLeft() { return m_Left; }
sf::FloatRect PlayableCharacter::GetRight() { return m_Right; }
sf::Sprite PlayableCharacter::GetSprite() { return m_Sprite; }

void PlayableCharacter::StopFalling(float position) {
    m_Position.y = position - GetPosition().height;
    m_Sprite.setPosition(m_Position);
    m_IsFalling = false;
}

void PlayableCharacter::StopRight(float position) {
    m_Position.x = position - m_Sprite.getGlobalBounds().width;
    m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::StopLeft(float position) {
    m_Position.x = position + m_Sprite.getGlobalBounds().width;
    m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::StopJump() {
    // Stop a jump early
    m_IsJumping = false;
    m_IsFalling = true;
}
