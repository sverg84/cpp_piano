#include "../include/WhitePianoKey.hpp"

WhitePianoKey::WhitePianoKey(
    const float& positionX,
    const sf::Keyboard::Key& key,
    const piano::SEMITONES_FROM_MIDDLE_A& semitone
): PianoKey(positionX, key, semitone, sf::Color::White) {}
