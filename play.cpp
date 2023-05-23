#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "hello" << std::endl;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Q:
                            window.close();
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }

    return 0;
}