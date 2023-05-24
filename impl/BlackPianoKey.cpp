#include "../include/namespace_piano.hpp"
#include "../include/BlackPianoKey.hpp"

BlackPianoKey::BlackPianoKey(
    PianoKey& other,
    const sf::Keyboard::Key& key,
    const piano::SEMITONES_FROM_MIDDLE_A& semitone
): PianoKey(other.getPosition().x, key, semitone, sf::Color::Black) {
    float rightTop = other.getPosition().x + piano::KEY_WIDTH;
    rect.setPosition(rightTop - piano::KEY_WIDTH / 4, 0);
    rect.setSize({piano::KEY_WIDTH / 2, piano::HEIGHT / 2});
}