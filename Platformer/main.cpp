#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ScreenManager.h"
#include "TileData.h"

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "SFML Platformer");

    // Window Manager
    ScreenManager::getInstance().initialize();
    ScreenManager::getInstance().loadContent();

    // Timing
    sf::Clock clock;
    float delta;
    const int ups = 60; // Updates Per Second

    // Main Game Loop
    while (window.isOpen()) {
        sf::Event event;

        if (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Resets the Window
        window.clear();

        // Timing
        delta += clock.restart().asSeconds();

        // Update and Render Cycles: CURRENTLY LIMITED AT 60 UPS
        if (delta >= 1 / ups) {
            ScreenManager::getInstance().update(window);
            ScreenManager::getInstance().render(window);
            delta = 0;
        }

        // Just Displays the Screen
        window.display();
    }

    return 0;
}
