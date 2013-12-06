#include "Level.h"

Level::Level() {

}

Level::~Level() {
    //dtor
}

void Level::loadLevel(const std::string& tilesetFile, char* file, unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;

    std::ifstream in(file);
    int buffer;
    for (unsigned int i = 0; i < width * height; i++) {
        in >> buffer;
        tiles.push_back(buffer);
    }
    in.close();

    std::cout << tiles.size() << std::endl;

    for (int i = 0; i < tiles.size(); i++) {
        std::cout << tiles.at(i) << std::endl;
    }

    if (!tmap.load(tilesetFile, sf::Vector2u(32, 32), tiles, width, height))
        std::cout << "Map is broken." << std::endl;
    std::cout << "Loaded" << std::endl;
}

void Level::generateLevel() {

}

void Level::unload() {
    tmap.unload();
}

void Level::update() {

}

void Level::render(sf::RenderWindow &window) {
    window.draw(tmap);
}


