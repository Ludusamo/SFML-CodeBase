#include "Level.h"

Level::Level(char* file)
{
    if (file != nullptr)
        loadLevel(file);
    else
        generateLevel();
}

Level::~Level()
{
    //dtor
}

void Level::loadLevel(char* file) {

}

void Level::generateLevel() {

}

void Level::update() {

}

void Level::render(sf::RenderWindow &window) {

}


