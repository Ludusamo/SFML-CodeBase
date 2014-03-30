#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include "System/Component.h"
#include "Screens/Screen.h"
#include "System/ScreenManager.h"
#include <SFML/Graphics.hpp>

class MainMenuScreen : public Screen {
public:
    MainMenuScreen();
    ~MainMenuScreen();

    void loadContent();
    void unloadContent();
    void update(sf::Time &delta);
    void render(sf::RenderWindow &window);
protected:
private:
    sf::Texture tex;
    Component main;
    sf::Text text;
    sf::Font font;
    std::vector<sf::Keyboard::Key> confirm;
};

#endif // MAINMENUSCREEN_H
