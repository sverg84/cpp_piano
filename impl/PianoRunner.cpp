#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/PianoRunner.hpp"
#include "../include/namespace_piano.hpp"


struct PianoRunner::PianoRunnerInternals {
    void eventHandler(sf::RenderWindow& window);
    void render(sf::RenderWindow& window, Piano& piano);
};


PianoRunner::PianoRunner(void): 
    window(sf::VideoMode(piano::WIDTH, piano::HEIGHT), "SFML"),
    ptr(std::make_unique<PianoRunner::PianoRunnerInternals>()) {}

PianoRunner::~PianoRunner(void) {}

void PianoRunner::run() {
    while (window.isOpen()) {
        ptr->eventHandler(window);
        ptr->render(window, piano);
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
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default:
                        break;
                }
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << event.mouseButton.x << std::endl;
                }
                break;
            default:
                break;
        }
    }
}

void PianoRunner::PianoRunnerInternals::render(sf::RenderWindow& window, Piano& piano) {
    window.clear(sf::Color::White);
    piano.render(window);
    window.display();
}