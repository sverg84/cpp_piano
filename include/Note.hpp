#include <SFML/Audio.hpp>
#include "namespace_piano.hpp"

#ifndef NOTE_HPP
#define NOTE_HPP

class Note : public sf::Sound {
    public:
        Note(const piano::SEMITONES_FROM_MIDDLE_A& semitone);

        virtual ~Note();
        sf::SoundBuffer buffer;
};

#endif