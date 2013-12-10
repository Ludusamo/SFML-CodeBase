#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <fstream>
#include <string>
#include <vector>

void generate_map(std::string filename, uint32_t width, uint32_t height, bool walls = true) {
	std::vector<std::vector<uint32_t> > map(width, std::vector<uint32_t>(height)); 
	int min_width = 0, min_height = 0, max_width = width, max_height = height;
	if(walls) {
		for(int i = 0; i < width; i++) {
			map[i][0] = 1;
			map[0][i] = 1;
			map[i][height - 1] = 1;
			map[width - 1][i] = 1;
		}
		++min_width;
		--max_width;
		++min_height;
		--max_height;
	}
	for(int i = min_width; i < max_width; i++)
		for(int j = min_height; j < max_height; j++)
			map[i][j] = rand() % 2;
//	for(int i = min_width; i < max_width; i++) {
//		for(int j = min_height; j < max_height; j++) {
//			
//		}
//	}
	std::ofstream out("random.lvl");
	out << width << " " << height << std::endl;
	for(int i = 0; i < width; i++) { 
		for(int j = 0; j < height - 1; j++) 
			out << (map[i][j] == 0 ? 2 : 1) << " ";
		out << (map[i][height - 1] == 0 ? 2 : 1) << std::endl;
	}
	out << std::endl;
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < height - 1; j++)
			out << map[i][j] << " ";
		out << map[i][height - 1] << std::endl;
	}
	out << std::endl;
	out.close();
}

int main(int argc, char ** argv) {
	generate_map("map.lvl", 10, 10, false);
	return 0;
}
