#pragma once

#include <SFML/Graphics.hpp>

#include "TextureHolder.h"

#include "Bob.h"
#include "Thomas.h"

#include "HUD.h"
#include "LevelManager.h"
#include "ParticleSystem.h"
#include "SoundManager.h"

class Engine {
  private:
    TextureHolder th;

    Thomas m_Thomas;
    Bob m_Bob;

    LevelManager m_LM;
    SoundManager m_SM;
    ParticleSystem m_PS;

    Hud m_Hud;
    int m_FrameSinceLastHudUpdate = 0;
    int m_TargetFramesPerHudUpdate = 500;

    const int TILE_SIZE = 50;
    const int VERTS_IN_QUAD = 4;

    const int GRAVITY = 300;

    sf::RenderWindow m_Window;

    sf::View m_MainView;
    sf::View m_LeftView;
    sf::View m_RightView;

    sf::View m_BGMainView;
    sf::View m_BGLeftView;
    sf::View m_BGRightView;

    sf::View m_HudView;

    sf::Sprite m_BackgroundSprite;
    sf::Texture m_BackgroundTexture;

    sf::Shader m_RippleShader;

    bool m_IsPlaying = false;
    bool m_Character1 = false;
    bool m_SplitScreen = false;

    float m_TimeRemaining = 10;
    sf::Time m_GameTimeTotal;

    bool m_NewLevelRequired = true;

    sf::VertexArray m_VALevel;
    int **m_ArrayLevel = NULL;

    sf::Texture m_TextureTiles;

    void Input();
    void Update(float);
    void Draw();

    void LoadLevel();
    bool DetectCollisions(PlayableCharacter &);

    void PopulateEmitters(std::vector<sf::Vector2f> &, int **);
    std::vector<sf::Vector2f> m_FireEmitters;

  public:
    Engine();
    void Run();
};
