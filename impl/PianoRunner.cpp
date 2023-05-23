#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/PianoRunner.hpp"


struct PianoRunner::PianoRunnerInternals {
    void eventHandler(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
};


PianoRunner::PianoRunner(void): 
    window(sf::VideoMode(1920, 1080), "SFML"),
    ptr(std::make_unique<PianoRunner::PianoRunnerInternals>()) {}

PianoRunner::~PianoRunner(void) {}

void PianoRunner::run() {
    while (window.isOpen()) {
        ptr->eventHandler(window);
    }
}

void PianoRunner::PianoRunnerInternals::eventHandler(sf::RenderWindow& window) {
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

void PianoRunner::PianoRunnerInternals::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
    window.display();
}