#ifndef TILEDATA_H
#define TILEDATA_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <SFML/Graphics.hpp>

class TileData {
public:
	static TileData * tiles;
	static TileData VOID;
	static TileData STONE;
	static TileData GRASS;

	uint32_t getId();
    sf::Color getLevelColor();
    uint32_t isSolid();

private:
    uint32_t id;
    sf::Color levelColor;
    bool solid;

    TileData(uint32_t id, sf::Color levelColor, bool solid);
};

#endif // TILEDATA_H
