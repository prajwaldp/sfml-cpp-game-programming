#pragma once

#include "Particle.h"

class ParticleSystem : public sf::Drawable {
  private:
    std::vector<Particle> m_Particles;
    sf::VertexArray m_Vertices;
    float m_Duration;
    bool m_IsRunning = false;

  public:
    virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
    void Init(int);
    void EmitParticles(sf::Vector2f);
    void Update(float);
    bool IsRunning();
};
