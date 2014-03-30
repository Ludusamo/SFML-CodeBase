#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Screens/Screen.h"
#include "System/ScreenManager.h"
#include "Screens/MainMenuScreen.h"
#include <SFML/Graphics.hpp>

class SplashScreen : public Screen {
public:
    SplashScreen();
    ~SplashScreen();

    void loadContent();
    void unloadContent();
    void update(sf::Time &delta);
    void render(sf::RenderWindow &window);
protected:
private:
    Screen newScreen;
    sf::Texture logoT;
    sf::Sprite logo;
    sf::Clock clock;
    sf::Time elapsed;
};

#endif // SPLASHSCREEN_H
