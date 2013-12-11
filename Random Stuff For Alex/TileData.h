#ifndef TILEDATA_H
#define TILEDATA_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct TileData {
	static TileData * tiles;
	static TileData VOID;
	static TileData STONE;
	static TileData GRASS;

private:
	uint32_t id;
	uint32_t levelColor;
	bool solid;
	
	TileData(uint32_t id, uint32_t levelColor, bool solid);
	uint32_t get_id(void);
	uint32_t get_level_color(void);
	uint32_t is_solid(void);
};
	
#endif
