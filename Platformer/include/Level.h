#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include <Tilemap.h>
#include <Player.h>
#include <vector>
#include <fstream>
#include <iostream>

#define TILE_SIZE 16
#define SCALE 2.0

class Level {
public:
    Level();
    ~Level();

    void loadLevel(const std::string& tilesetFile, const std::string&  file);
    void unload();
    void update();
    void render(sf::RenderWindow &window);
    Player &getPlayer();
protected:
private:
    void generateLevel();
    int width, height;
    std::vector<int> tiles;
    Tilemap tmap;
    Player player;
    sf::Texture pTex;
};
#endif // LEVEL_H
