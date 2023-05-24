#include <iostream>
#include "../include/namespace_piano.hpp"
#include "../include/Piano.hpp"
#include "../include/BlackPianoKey.hpp"
#include "../include/WhitePianoKey.hpp"

Piano::Piano() {
    pianoKeys.reserve(piano::NUM_WHITE_KEYS + piano::NUM_BLACK_KEYS);

    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        const float positionX = i * (piano::KEY_WIDTH + piano::KEY_OUTLINE_THICKNESS);
        const auto& keyAndNote = piano::WHITE_KEYS[i];
        pianoKeys.push_back(WhitePianoKey(positionX, keyAndNote.first, keyAndNote.second));
    }

    int blackKeySkip = 2;
    int blackKeyIndex = 0;
    int skipIndex = 0;
    for (int i = 0; i < piano::NUM_WHITE_KEYS; i++) {
        if (skipIndex++ != blackKeySkip && blackKeyIndex < piano::NUM_BLACK_KEYS) {
            const auto& keyAndNote = piano::BLACK_KEYS[blackKeyIndex++];
            pianoKeys.push_back(BlackPianoKey(pianoKeys[i], keyAndNote.first, keyAndNote.second));
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