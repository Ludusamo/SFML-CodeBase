#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include "Screens/Screen.h"
#include "Screens/MainMenuScreen.h"
#include "Screens/SplashScreen.h"
#include "Screens/GameScreen.h"
#include "Transition/FadeTransition.h"
#include "FileManager.h"

#define WIDTH 640
#define HEIGHT 640

class ScreenManager {
public:
    ~ScreenManager();
    static ScreenManager &getInstance();

    void initialize();
    void loadContent();
    void switchScreen();
    void update(sf::RenderWindow &window, sf::Time delta);
    void render(sf::RenderWindow &window);

    void addScreen(Screen *screen);

    float getAlpha();
protected:
private:
    //Screen *currentScreen, *newScreen;

    ScreenManager();
    ScreenManager(ScreenManager const&);
    void operator = (ScreenManager const&);

    void Transition(sf::RenderWindow &window);
    bool transition;

    Screen *newScreen;
    FadeTransition fade;

    sf::RectangleShape fadeBackground;
};

#endif // SCREENMANAGER_H
