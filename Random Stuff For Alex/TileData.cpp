#include "TileData.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

TileData::TileData(uint32_t id, uint32_t levelColor, bool solid) {
	this->id = id;
	this->levelColor = levelColor;
	this->solid = solid;
	tiles = (TileData*) malloc(sizeof(TileData) * 256);
	tiles[id] = *this;
}

uint32_t TileData::get_id(void) {
	return this->id;
	return this->id;
}

uint32_t TileData::get_level_color(void) {
	return this->levelColor;
}

uint32_t TileData::is_solid(void) {
	return this->solid;
}
