#include "Level/Tilemap.h"

Tilemap::Tilemap() {
    //ctor
}

Tilemap::~Tilemap() {
    //dtor
}

bool Tilemap::load(const std::string& tilesetFile, sf::Vector2u tileSize, const std::vector<int> tiles, unsigned int width, unsigned int height) {
    if (!tileset.loadFromFile(tilesetFile))
        return false;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (unsigned int x = 0; x < width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int tilenum = tiles[x + y * width];

            int xx = tilenum % (tileset.getSize().x / tileSize.x);
            int yy = tilenum / (tileset.getSize().x / tileSize.x);

            sf::Vertex* quad = &m_vertices[(x + y * width) * 4];

            quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
            quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
            quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);

            quad[0].texCoords = sf::Vector2f(xx * tileSize.x, yy * tileSize.y);
            quad[1].texCoords = sf::Vector2f((xx + 1) * tileSize.x, yy * tileSize.y);
            quad[2].texCoords = sf::Vector2f((xx + 1) * tileSize.x, (yy + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(xx * tileSize.x, (yy + 1) * tileSize.y);
        }
    }
    return true;
}

bool Tilemap::generateLevel() {
    return true;
}

bool Tilemap::unload() {
    m_vertices.clear();
    return true;
}

