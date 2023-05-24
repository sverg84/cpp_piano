#include "../include/PianoKey.hpp"
#include "../include/namespace_piano.hpp"

PianoKey::PianoKey(
    const float& positionX,
    const sf::Keyboard::Key& key,
    const piano::SEMITONES_FROM_MIDDLE_A& semitone,
    const sf::Color& color
): key(key), color(color), note(semitone) {
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
    if (note.getBuffer() == nullptr)
        note.setBuffer(note.buffer);

    if (sf::Keyboard::isKeyPressed(key)) {
        if (note.getStatus() != Note::Playing) {
            note.play();
            rect.setFillColor(sf::Color::Green);
        }
    }
    else {
        note.stop();
        rect.setFillColor(color);
    }

    renderTarget.draw(rect);
}