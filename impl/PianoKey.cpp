#include "../include/PianoKey.hpp"
#include "../include/namespace_piano.hpp"

PianoKey::PianoKey(const float& keyWidth, const float& positionX) {
    // all placeholder / proof-of-concept
    rect.setFillColor(sf::Color::White);
    rect.setPosition({positionX, 0});
    rect.setSize({keyWidth, piano::HEIGHT});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(piano::KEY_OUTLINE_THICKNESS);
}

PianoKey::~PianoKey(void) {}

void PianoKey::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(rect);
}