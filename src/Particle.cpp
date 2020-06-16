#include "Particle.h"

Particle::Particle(sf::Vector2f direction) {
    m_Velocity.x = direction.x;
    m_Velocity.y = direction.y;
}

void Particle::Update(float dt) { m_Position += m_Velocity * dt; }

void Particle::SetPosition(sf::Vector2f position) { m_Position = position; }

sf::Vector2f Particle::GetPosition() { return m_Position; }
