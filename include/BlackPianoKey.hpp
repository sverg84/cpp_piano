#include "PianoKey.hpp"

#ifndef BLACK_PIANO_KEY_HPP
#define BLACK_PIANO_KEY_HPP

class BlackPianoKey : public PianoKey {
    public:
        BlackPianoKey(
            PianoKey& other,
            const float& keyWidth,
            const sf::Keyboard::Key& key
        );
};

#endif