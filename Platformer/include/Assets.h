#ifndef ASSETS_H
#define ASSETS_H

#include <SFML/Graphics.hpp>

class Assets
{
    public:
        Assets();
        ~Assets();

        static sf::Texture TilesetA;

        void load();
        void unload();
    protected:
    private:
};

#endif // ASSETS_H
