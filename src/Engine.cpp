#include "Engine.h"

Engine::Engine() {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    m_Window.create(sf::VideoMode(resolution.x, resolution.y),
                    "Thomas was Late", sf::Style::Resize);

    m_MainView.setSize(resolution);
    m_HudView.reset(sf::FloatRect(0, 0, resolution.x, resolution.y));

    m_LeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_RightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

    m_BGLeftView.setViewport(sf::FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_BGRightView.setViewport(sf::FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

    if (!sf::Shader::isAvailable()) {
        m_Window.close();
    } else {
        std::cout << "Trying to load shader\n";
        m_RippleShader.loadFromFile("shaders/vertShader.vert",
                                    "shaders/rippleShader.frag");
        std::cout << "Loaded shader\n";
    }

    m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);

    // Load the texture for the background vertex array
    m_TextureTiles = TextureHolder::GetTexture("graphics/tiles_sheet.png");

    m_PS.Init(1000);
}

void Engine::Run() {
    sf::Clock clock;

    while (m_Window.isOpen()) {
        sf::Time dt = clock.restart();
        m_GameTimeTotal += dt;
        float dtAsSeconds = dt.asSeconds();

        Input();
        Update(dtAsSeconds);
        Draw();
    }
}
