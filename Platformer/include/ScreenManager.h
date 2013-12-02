#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include "Screen.h"
#include "MainMenuScreen.h"
#include "SplashScreen.h"
#include "FadeTransition.h"
#include "FileManager.h"

#define WIDTH 800
#define HEIGHT 600

class ScreenManager {
public:
    ~ScreenManager();
    static ScreenManager &getInstance();

    void initialize();
    void loadContent();
    void switchScreen();
    void update(sf::RenderWindow &window, sf::Event event);
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

    std::vector<std::vector<std::string>> attributes;
    std::vector<std::vector<std::string>> content;
    FileManager file;
};

#endif // SCREENMANAGER_H
