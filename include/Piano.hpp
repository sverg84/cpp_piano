#include "PianoKey.hpp"

#ifndef PIANO_HPP
#define PIANO_HPP

class Piano {
    public:
        Piano();

        ~Piano();

        virtual void render(sf::RenderTarget& renderTarget);

    private:
        PianoKey pianoKey;
};

#endif
