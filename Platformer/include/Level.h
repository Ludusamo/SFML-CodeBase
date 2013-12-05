#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <SFML/Graphics.hpp>

class Level
{
    public:
        Level(char* file);
        ~Level();

        void update();
        void render(sf::RenderWindow &window);
    protected:
    private:
        void loadLevel(char* file);
        void generateLevel();
        //Tile tilemap[];
};

#endif // LEVEL_H
