#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/Piano.hpp"
#include "../include/BlackPianoKey.hpp"
#include "../include/WhitePianoKey.hpp"

Piano::Piano() {
    pianoKeys.reserve(piano::NUM_WHITE_KEYS + piano::NUM_BLACK_KEYS);

    const float keyWidth = 
        (piano::WIDTH - (piano::NUM_WHITE_KEYS * piano::KEY_OUTLINE_THICKNESS)) / piano::NUM_WHITE_KEYS;

    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        const float positionX = i * (keyWidth + piano::KEY_OUTLINE_THICKNESS);
        WhitePianoKey whiteKey(keyWidth, positionX, piano::WHITE_KEYS[i]);
        pianoKeys.push_back(whiteKey);
    }

    int blackKeySkip = 2;
    int blackKeyIndex = 0;
    int pls = 0;
    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        if (pls++ != blackKeySkip && blackKeyIndex < piano::NUM_BLACK_KEYS) {
            BlackPianoKey blackKey(pianoKeys[i], keyWidth, piano::BLACK_KEYS[blackKeyIndex++]);
            pianoKeys.push_back(blackKey);
        }
        else {
            blackKeySkip = blackKeySkip == 2 ? 3 : 2;
            pls = 0;
        }
    }
}

Piano::~Piano(void) {}

void Piano::render(sf::RenderTarget& renderTarget) {
    for (PianoKey& pianoKey : pianoKeys)
        pianoKey.render(renderTarget);
}