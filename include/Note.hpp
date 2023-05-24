#include <SFML/Audio.hpp>

#ifndef NOTE_HPP
#define NOTE_HPP

class Note : public sf::Sound {
    public:
        Note();

        virtual ~Note();

    private:
        sf::SoundBuffer buffer;
};

#endif