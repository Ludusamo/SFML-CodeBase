#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Screens/Screen.h"
#include "System/ScreenManager.h"
#include "Level/Level.h"
#include <SFML/Graphics.hpp>

class GameScreen : public Screen {
public:
    GameScreen();
    ~GameScreen();

    void loadContent();
    void unloadContent();
    void update(sf::Time delta);
    void render(sf::RenderWindow &window);
protected:
private:
    Level level;
    std::vector<sf::Keyboard::Key> up;
    std::vector<sf::Keyboard::Key> down;
    std::vector<sf::Keyboard::Key> left;
    std::vector<sf::Keyboard::Key> right;

    sf::Vector2f center;
    sf::View mainView;
};

#endif // GAMESCREEN_H
