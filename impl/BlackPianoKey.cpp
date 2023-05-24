#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/BlackPianoKey.hpp"

BlackPianoKey::BlackPianoKey(
    PianoKey& other,
    const sf::Keyboard::Key& key
): PianoKey(other.getPosition().x, key, sf::Color::Black) {
    float rightTop = other.getPosition().x + piano::KEY_WIDTH;
    rect.setPosition(rightTop - piano::KEY_WIDTH / 4, 0);
    rect.setSize({piano::KEY_WIDTH / 2, piano::HEIGHT / 2});
}