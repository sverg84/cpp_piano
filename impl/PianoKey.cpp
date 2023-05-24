#include <iostream>
#include "../include/PianoKey.hpp"
#include "../include/namespace_piano.hpp"

PianoKey::PianoKey(
    const float& positionX,
    const sf::Keyboard::Key& key,
    const sf::Color& color
): key(key) {
    rect.setFillColor(color);
    rect.setPosition({positionX, 0});
    rect.setSize({piano::KEY_WIDTH, piano::HEIGHT});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(piano::KEY_OUTLINE_THICKNESS);
}

PianoKey::~PianoKey(void) {}

const sf::Vector2f& PianoKey::getPosition() {
    return rect.getPosition();
}

void PianoKey::render(sf::RenderTarget& renderTarget) {
    renderTarget.draw(rect);
}