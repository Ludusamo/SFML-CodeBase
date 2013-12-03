#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Screen.h"
#include "ScreenManager.h"
#include <SFML/Graphics.hpp>

class SplashScreen : public Screen {
public:
    SplashScreen();
    ~SplashScreen();

    void loadContent();
    void unloadContent();
    void update(float delta);
    void render(sf::RenderWindow &window);
protected:
private:
    sf::Text text;
    sf::Font font;
};

#endif // SPLASHSCREEN_H
