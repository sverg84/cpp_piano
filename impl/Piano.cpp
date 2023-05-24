#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/Piano.hpp"

Piano::Piano() {
    pianoKeys.reserve(piano::NUM_WHITE_KEYS);

    const float keyWidth = 
        (piano::WIDTH - (piano::NUM_WHITE_KEYS * piano::KEY_OUTLINE_THICKNESS)) / piano::NUM_WHITE_KEYS;

    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        const float positionX = i * (keyWidth + piano::KEY_OUTLINE_THICKNESS);
        PianoKey pianoKey(keyWidth, positionX);
        pianoKeys.push_back(pianoKey);
    }
}

Piano::~Piano(void) {}

void Piano::render(sf::RenderTarget& renderTarget) {
    for (PianoKey& pianoKey : pianoKeys)
        pianoKey.render(renderTarget);
}