#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/PianoRunner.hpp"
#include "../include/namespace_piano.hpp"


struct PianoRunner::PianoRunnerInternals {
    void eventHandler(sf::RenderWindow& window, bool& isInFocus);
    void render(sf::RenderWindow& window, Piano& piano, const bool& isInFocus);
};


PianoRunner::PianoRunner(void): 
    window(sf::VideoMode(piano::WIDTH, piano::HEIGHT), "Virtual Piano"),
    ptr(std::make_unique<PianoRunner::PianoRunnerInternals>()) {}

PianoRunner::~PianoRunner(void) {}

void PianoRunner::run() {
    while (window.isOpen()) {
        ptr->eventHandler(window, isInFocus);
        ptr->render(window, piano, isInFocus);
    }
}

void PianoRunner::PianoRunnerInternals::eventHandler(
    sf::RenderWindow& window, 
    bool& isInFocus
) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::GainedFocus:
                isInFocus = true;
                break;
            case sf::Event::LostFocus:
                isInFocus = false;
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
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

void PianoRunner::PianoRunnerInternals::render(
    sf::RenderWindow& window,
    Piano& piano,
    const bool& isInFocus
) {
    if (!isInFocus)
        return;
    window.clear(sf::Color::White);
    piano.render(window);
    window.display();
}