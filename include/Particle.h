#pragma once

#include <SFML/Graphics.hpp>

class Particle {
  private:
    sf::Vector2f m_Position;
    sf::Vector2f m_Velocity;

  public:
    Particle(sf::Vector2f);
    void Update(float);
    void SetPosition(sf::Vector2f);
    sf::Vector2f GetPosition();
};
