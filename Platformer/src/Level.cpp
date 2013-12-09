#include "Level.h"

Level::Level() {

}

Level::~Level() {
    //dtor
}

void Level::loadLevel(const std::string& tilesetFile, const std::string&  file) {
    std::ifstream in(file);
    in >> width >> height;

    // Loading Map
    int buffer;
    for (int i = 0; i < width * height; i++) {
        in >> buffer;
        tiles.push_back(buffer);
    }

    // Loading Collision Map
    std::vector<int> bufferV;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            in >> buffer;
            bufferV.push_back(buffer);
        }
        colMap.push_back(bufferV);
        bufferV.clear();
    }
    in.close();

    if (!tmap.load(tilesetFile, sf::Vector2u(32, 32), tiles, width, height))
        std::cout << "Map could not be loaded." << std::endl;

    pTex.loadFromFile("res/imgs/player.png");
    player.load(sf::Vector2f(2, 7), pTex, 2, sf::Vector2i(16, 16));
}

void Level::generateLevel() {

}

void Level::unload() {
    tmap.unload();
    player.unload();
}

void Level::update() {
    player.update(colMap);
}

void Level::render(sf::RenderWindow &window) {
    window.draw(tmap);
    window.draw(player);
}

Player &Level::getPlayer() {
    return player;
}

std::vector<std::vector<int>> Level::getColMap() {
    return colMap;
}
