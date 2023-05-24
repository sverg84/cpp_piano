#include "PianoKey.hpp"

#ifndef PIANO_HPP
#define PIANO_HPP

class Piano {
    public:
        Piano();

        virtual ~Piano();

        void render(sf::RenderTarget& renderTarget);

    private:
        std::vector<PianoKey> pianoKeys;
};

#endif
