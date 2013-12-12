#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Screen.h"
#include "ScreenManager.h"
#include "MainMenuScreen.h"
#include <SFML/Graphics.hpp>

class SplashScreen : public Screen {
public:
    SplashScreen();
    ~SplashScreen();

    void loadContent();
    void unloadContent();
    void update();
    void render(sf::RenderWindow &window);
protected:
private:
    Screen newScreen;
    sf::Texture logoT;
    sf::Sprite logo;
    sf::Clock clock;
    float delta;
};

#endif // SPLASHSCREEN_H
