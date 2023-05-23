#include <SFML/Graphics.hpp>
#include "../include/PianoRunner.hpp"

PianoRunner::PianoRunner(void) {}

PianoRunner::~PianoRunner(void) {}

void PianoRunner::run() {
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
}