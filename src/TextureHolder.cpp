#include "TextureHolder.h"

TextureHolder *TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
    bool ok = m_s_Instance == nullptr;
    if (!ok) {
        std::cout << "Duplicate Instance. Exiting" << std::endl;
    }
    m_s_Instance = this;
}

sf::Texture &TextureHolder::GetTexture(std::string const &filename) {
    auto &m = m_s_Instance->m_Textures;
    auto it = m.find(filename);
    if (it != m.end()) {
        return it->second;
    }

    auto &texture = m[filename];
    texture.loadFromFile(filename);
    return texture;
}
