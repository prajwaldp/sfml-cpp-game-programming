#include "ParticleSystem.h"
#include "math.h"

void ParticleSystem::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
    target.draw(m_Vertices, states);
}

void ParticleSystem::Init(int num_particles) {
    m_Vertices.setPrimitiveType(sf::Points);
    m_Vertices.resize(num_particles);

    for (int i = 0; i < num_particles; i++) {
        srand(time(0) + i);
        float angle = (rand() % 360) * 3.14f / 180.f;
        float speed = (rand() % 600) + 600.f;

        sf::Vector2f direction;
        direction = sf::Vector2f(cos(angle) * speed, sin(angle) * speed);
        m_Particles.push_back(Particle(direction));
    }
}

void ParticleSystem::Update(float dt) {
    m_Duration -= dt;
    int current_vertex = 0;

    for (auto it = m_Particles.begin(); it != m_Particles.end(); it++) {
        (*it).Update(dt);
        m_Vertices[current_vertex].position = (*it).GetPosition();
        current_vertex++;
    }

    if (m_Duration < 0) {
        m_IsRunning = false;
    }
}

void ParticleSystem::EmitParticles(sf::Vector2f start_position) {
    m_IsRunning = true;
    m_Duration = 2;

    int current_vertex = 0;
    for (auto it = m_Particles.begin(); it != m_Particles.end(); it++) {
        m_Vertices[current_vertex].color = sf::Color::Yellow;
        (*it).SetPosition(start_position);
        current_vertex++;
    }
}

bool ParticleSystem::IsRunning() { return m_IsRunning; }
