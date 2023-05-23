#include "../include/PianoKey.hpp"

PianoKey::PianoKey(void) {
    // all placeholder / proof-of-concept
    rect.setFillColor(sf::Color::Blue);
    rect.setSize({100, 100});
    rect.setOutlineColor(sf::Color::Black);
}

PianoKey::~PianoKey(void) {}

void PianoKey::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(rect);
}