#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "System/ScreenManager.h"
#include "Level/TileData.h"
#include "MapGenerator.h"

int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT, 32), "SFML Platformer");

    // Window Manager
    ScreenManager::getInstance().initialize();
    ScreenManager::getInstance().loadContent();

    // Timing
    sf::Clock clock;
    sf::Time delta;
    const sf::Time ups = sf::seconds(1.0f / 120.0f); // Updates Per Second

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
        delta += clock.restart();

        // Update Cycles: CURRENTLY LIMITED AT 120 UPS
        if (delta >= ups) {
            ScreenManager::getInstance().update(window, delta);
            delta = sf::Time::Zero;
        }
        ScreenManager::getInstance().render(window);

         // Just Displays the Screen
        window.display();

    }

    return 0;
}
