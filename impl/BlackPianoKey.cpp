#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/BlackPianoKey.hpp"

BlackPianoKey::BlackPianoKey(
    PianoKey& other,
    const float& keyWidth,
    const sf::Keyboard::Key& key
): PianoKey(keyWidth, other.getPosition().x, key, sf::Color::Black) {
    float rightTop = other.getPosition().x + keyWidth;
    rect.setPosition(rightTop - keyWidth / 4, 0);
    rect.setSize({keyWidth / 2, piano::HEIGHT / 2});
}