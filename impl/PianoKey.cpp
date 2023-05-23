#include "../include/PianoKey.hpp"
#include "../include/namespace_piano.hpp"

PianoKey::PianoKey(void) {
    // all placeholder / proof-of-concept
    rect.setFillColor(sf::Color::Blue);
    rect.setSize({100, piano::HEIGHT});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(piano::KEY_OUTLINE_THICKNESS);
}

PianoKey::~PianoKey(void) {}

void PianoKey::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(rect);
}