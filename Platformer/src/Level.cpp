#include "Level.h"

Level::Level() {

}

Level::~Level() {
    //dtor
}

void Level::loadLevel(const std::string& tilesetFile, const std::string&  file) {
    std::ifstream in(file);
    in >> width >> height;
    int buffer;
    for (int i = 0; i < width * height; i++) {
        in >> buffer;
        tiles.push_back(buffer);
    }
    in.close();

    if (!tmap.load(tilesetFile, sf::Vector2u(32, 32), tiles, width, height))
        std::cout << "Map could not be loaded." << std::endl;
    tmap.setScale(SCALE, SCALE);

    pTex.loadFromFile("res/imgs/player.png");
    player.load(sf::Vector2f(100, 100), pTex, 2);
    player.setScale(SCALE, SCALE);
}

void Level::generateLevel() {

}

void Level::unload() {
    tmap.unload();
    player.unload();
}

void Level::update() {
    player.moveM();
}

void Level::render(sf::RenderWindow &window) {
    window.draw(tmap);
    window.draw(player);
}

Player &Level::getPlayer() {
    return player;
}

