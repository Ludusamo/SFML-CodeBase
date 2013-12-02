#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ScreenManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "SFML Platformer");

    ScreenManager::getInstance().initialize();
    ScreenManager::getInstance().loadContent();

    while (window.isOpen()) {
        sf::Event event;

        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        ScreenManager::getInstance().update(window, event);
        ScreenManager::getInstance().render(window);

        window.display();
    }

    return 0;
}
