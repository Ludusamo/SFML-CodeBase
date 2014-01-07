#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
public:
    Tile();
    ~Tile();

    virtual void update();
    virtual void render(sf::RenderWindow &window);
protected:
    int id;
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Texture tex;
private:
};

#endif // TILE_H
