#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter {
  protected:
    sf::Sprite m_Sprite;
    float m_JumpDuration;

    bool m_IsJumping;
    bool m_IsFalling;

    bool m_LeftPressed;
    bool m_RightPressed;

    float m_TimeThisJump; // How long has this jump lasted for
    bool m_JustJumped;

  private:
    float m_Gravity;
    float m_Speed = 400;
    sf::Vector2f m_Position;

    sf::FloatRect m_Feet;
    sf::FloatRect m_Head;
    sf::FloatRect m_Right;
    sf::FloatRect m_Left;

    sf::Texture m_Texture;

  public:
    void Spawn(sf::Vector2f, float);
    virtual bool HandleInput() = 0;

    sf::FloatRect GetPosition();
    sf::FloatRect GetFeet();
    sf::FloatRect GetHead();
    sf::FloatRect GetRight();
    sf::FloatRect GetLeft();

    sf::Sprite GetSprite();

    void StopFalling(float);
    void StopRight(float);
    void StopLeft(float);
    void StopJump();

    sf::Vector2f GetCenter();

    void Update(float);
};
