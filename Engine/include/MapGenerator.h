#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>
#include <utility>
#include <assert.h>

class MapGenerator {
private:
    class Component {
    private:
        std::string id;
        std::vector<std::vector<int16_t> > componentMap;

    public:
        Component(void);
        Component(std::string filename);
        Component(std::string id, std::vector<std::vector<int16_t> > componentMap);
        Component(const MapGenerator::Component &other);
        ~Component(void);
        std::string get_id(void);
        std::vector<std::vector<int16_t> > get_component_map(void);
        void set_id(std::string id);
        void set_component_map(std::vector<std::vector<int16_t> > componentMap);
        void populate(std::string filename);
        void populate(std::string id, std::vector<std::vector<int16_t> > componentMap);
        void populate(const MapGenerator::Component other);
        MapGenerator::Component& operator=(const MapGenerator::Component other);
        void paint_to(std::vector<std::vector<int16_t> > &generation, bool walls);
        void paint_to(uint32_t xpos, uint32_t ypos, std::vector<std::vector<int16_t> > &generation, bool walls);
    };

    typedef std::pair<uint32_t,uint32_t> coordinate_t;

    bool walls;
    std::vector<Component> resources;
    std::vector<std::vector<int16_t> > generation;
    std::vector<coordinate_t> blacklist;
    std::vector<std::vector<coordinate_t> > subsets;

public:
	MapGenerator(void);
	MapGenerator(std::string file);
	MapGenerator(std::vector<std::string> files);
	MapGenerator(const MapGenerator &other);
	~MapGenerator(void);
	void fetch_resources(std::string file);
	void fetch_resources(std::vector<std::string> files);
	void append_resources(std::string file);
	void append_resources(std::vector<std::string> files);
	void remove_resources(uint32_t index);
	void remove_resources(std::string id);
	void clear_resources(void);
	void set_resources(std::string file);
	void set_resources(std::vector<std::string> files);
	void set_walls(bool walls);
	std::vector<std::string> get_resources(void);
	bool has_walls(void);
	uint32_t get_solids(void);
	void connect_nodes(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
	void check_node(uint32_t x, uint32_t y, bool silent);
	void fix_generation(void);
	std::vector<std::vector<int16_t> > generate(uint32_t width, uint32_t height, float weight);
	std::vector<std::vector<int16_t> > generate(uint32_t width, uint32_t height, std::vector<float> weights);
};

#endif
