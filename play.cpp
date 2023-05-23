#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "hello" << std::endl;

    sf::Window window(sf::VideoMode(1920, 1080), "SFML");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}