#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Tilemap.h>
#include <vector>
#include <fstream>
#include <iostream>

#define TILE_SIZE 16

class Level {
public:
    Level();
    ~Level();

    void loadLevel(const std::string& tilesetFile, char* file, unsigned int width, unsigned int height);
    void update();
    void render(sf::RenderWindow &window);
    void unload();
protected:
private:
    void generateLevel();
    int width, height;
    std::vector<int> tiles;
    Tilemap tmap;
};
#endif // LEVEL_H
