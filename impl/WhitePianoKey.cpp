#include "../include/WhitePianoKey.hpp"

WhitePianoKey::WhitePianoKey(
    const float& keyWidth,
    const float& positionX,
    const sf::Keyboard::Key& key
): PianoKey(keyWidth, positionX, key, sf::Color::White) {}
