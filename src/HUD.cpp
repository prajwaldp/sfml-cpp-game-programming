#include "HUD.h"

Hud::Hud() {
    sf::Vector2u resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    // Load the font
    m_Font.loadFromFile("fonts/Roboto-Light.ttf");

    // Paused
    m_StartText.setFont(m_Font);
    m_StartText.setCharacterSize(100);
    m_StartText.setFillColor(sf::Color::White);
    m_StartText.setString("Press Enter when ready!");

    // Position the text
    sf::FloatRect text_rect = m_StartText.getLocalBounds();

    m_StartText.setOrigin(text_rect.left + text_rect.width / 2.0f,
                          text_rect.top + text_rect.height / 2.0f);

    m_StartText.setPosition(resolution.x / 2.0f, resolution.y / 2.0f);

    // Time
    m_TimeText.setFont(m_Font);
    m_TimeText.setCharacterSize(75);
    m_TimeText.setFillColor(sf::Color::White);
    m_TimeText.setPosition(resolution.x - 150, 0);
    m_TimeText.setString("------");

    // Level
    m_LevelText.setFont(m_Font);
    m_LevelText.setCharacterSize(75);
    m_LevelText.setFillColor(sf::Color::White);
    m_LevelText.setPosition(25, 0);
    m_LevelText.setString("1");
}

sf::Text Hud::GetMessage() { return m_StartText; }

sf::Text Hud::GetLevel() { return m_LevelText; }

sf::Text Hud::GetTime() { return m_TimeText; }

void Hud::SetLevel(sf::String text) { m_LevelText.setString(text); }

void Hud::SetTime(sf::String text) { m_TimeText.setString(text); }
