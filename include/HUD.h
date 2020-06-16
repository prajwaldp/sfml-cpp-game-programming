#pragma once
#include <SFML/Graphics.hpp>

class Hud {
  private:
    sf::Font m_Font;
    sf::Text m_StartText;
    sf::Text m_TimeText;
    sf::Text m_LevelText;

  public:
    Hud();

    sf::Text GetMessage();
    sf::Text GetLevel();
    sf::Text GetTime();

    void SetLevel(sf::String text);
    void SetTime(sf::String text);
};
