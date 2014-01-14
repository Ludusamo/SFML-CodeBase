#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>
#include "TileData.h"
#include "Level/Tilemap.h"
#include "Entity/Player.h"
#include "MapGenerator.h"
#include <vector>
#include <fstream>
#include <iostream>

#define TILE_SIZE 32
#define SCALE 2.0

class Level {
public:
    Level();
    ~Level();

    void load();
    void loadLevel(const std::string& tilesetFile, const std::string&  file);
    void saveLevel();
    void generateLevel(const std::string& tilesetFile, int widthB, int heightB);
    void unload();
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
    Player &getPlayer();
    std::vector<std::vector<int>> getColMap();

    int getWidth();
    int getHeight();

    // TEMPORARY
    void switchTime(bool day);
protected:
private:
    // Map
    int width, height;
    std::vector<int> tiles;
    Tilemap tmap;
    std::vector<std::vector<int>> colMap;
    std::string name;

    // Player
    Player player;
    sf::Texture pTex;

    // Shader
    sf::Shader shader;
    float ambientIntensity = .7f;
    sf::Vector3f ambientColor;
};
#endif // LEVEL_H
