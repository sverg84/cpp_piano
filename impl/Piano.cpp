#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/Piano.hpp"
#include "../include/BlackPianoKey.hpp"
#include "../include/WhitePianoKey.hpp"

Piano::Piano() {
    pianoKeys.reserve(piano::NUM_WHITE_KEYS + piano::NUM_BLACK_KEYS);

    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        const float positionX = i * (piano::KEY_WIDTH + piano::KEY_OUTLINE_THICKNESS);
        pianoKeys.push_back(WhitePianoKey(positionX, piano::WHITE_KEYS[i]));
    }

    int blackKeySkip = 2;
    int blackKeyIndex = 0;
    int skipIndex = 0;
    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        if (skipIndex++ != blackKeySkip && blackKeyIndex < piano::NUM_BLACK_KEYS) {
            pianoKeys.push_back(BlackPianoKey(pianoKeys[i], piano::BLACK_KEYS[blackKeyIndex++]));
        }
        else {
            blackKeySkip = blackKeySkip == 2 ? 3 : 2;
            skipIndex = 0;
        }
    }
}

Piano::~Piano(void) {}

void Piano::render(sf::RenderTarget& renderTarget) {
    for (PianoKey& pianoKey : pianoKeys)
        pianoKey.render(renderTarget);
}