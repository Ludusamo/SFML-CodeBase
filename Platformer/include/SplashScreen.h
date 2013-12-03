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
};

#endif // SPLASHSCREEN_H
