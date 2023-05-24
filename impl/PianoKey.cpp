#include <iostream>
#include "../include/PianoKey.hpp"
#include "../include/namespace_piano.hpp"

PianoKey::PianoKey(
    const float& keyWidth,
    const float& positionX,
    const sf::Keyboard::Key& key,
    const sf::Color& color
): key(key) {
    rect.setFillColor(color);
    rect.setPosition({positionX, 0});
    rect.setSize({keyWidth, piano::HEIGHT});
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(piano::KEY_OUTLINE_THICKNESS);
}

PianoKey::~PianoKey(void) {}

const sf::Vector2f& PianoKey::getPosition() {
    return rect.getPosition();
}

const sf::Vector2f& PianoKey::getSize() {
    return rect.getSize();
}

void PianoKey::render(sf::RenderTarget& renderTarget) {
    // std::cout << key << std::endl;
    renderTarget.draw(rect);
}