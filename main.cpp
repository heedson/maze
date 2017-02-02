#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"

#include "helper.h"
#include "game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WindowSize, WindowSize), "Maze");
    window.setFramerateLimit(60);

    Game game(&window);

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Time dt = deltaClock.restart(); 

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        game.Update(dt.asSeconds());
        game.Render();
    }

    return 0;
}
