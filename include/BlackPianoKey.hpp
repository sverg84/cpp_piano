#include "PianoKey.hpp"

#ifndef BLACK_PIANO_KEY_HPP
#define BLACK_PIANO_KEY_HPP

class BlackPianoKey : public PianoKey {
    public:
        BlackPianoKey(
            PianoKey& other,
            const sf::Keyboard::Key& key,
            const piano::SEMITONES_FROM_MIDDLE_A& semitone
        );
};

#endif