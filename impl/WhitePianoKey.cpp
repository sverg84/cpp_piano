#include "../include/WhitePianoKey.hpp"

WhitePianoKey::WhitePianoKey(
    const float& positionX,
    const sf::Keyboard::Key& key
): PianoKey(positionX, key, sf::Color::White) {}
