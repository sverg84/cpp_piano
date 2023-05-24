#include "PianoKey.hpp"

#ifndef WHITE_PIANO_KEY_HPP
#define WHITE_PIANO_KEY_HPP

class WhitePianoKey : public PianoKey {
    public:
        WhitePianoKey(
            const float& positionX,
            const sf::Keyboard::Key& key
        );
};

#endif