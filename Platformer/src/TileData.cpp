#include "TileData.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

TileData * TileData::tiles = (TileData*) malloc(sizeof(TileData) * 256);
TileData TileData::VOID(0, sf::Color(0, 0, 0), true);
TileData TileData::STONE(1, sf::Color(68, 68, 68), true);
TileData TileData::GRASS(2, sf::Color(0, 255, 0), false);

TileData::TileData(uint32_t id, sf::Color levelColor, bool solid) {
	this->id = id;
	this->levelColor = levelColor;
	this->solid = solid;
	tiles[id] = *this;
}

uint32_t TileData::getId() {
	return this->id;
	return this->id;
}

sf::Color TileData::getLevelColor() {
	return this->levelColor;
}

uint32_t TileData::isSolid() {
	return this->solid;
}
