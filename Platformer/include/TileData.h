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
    bool isSolid();
    bool isEmitter();

private:
    uint32_t id;
    sf::Color levelColor;
    bool solid, emitter;

    TileData(uint32_t id, sf::Color levelColor, bool solid, bool emitter);
};

#endif // TILEDATA_H
