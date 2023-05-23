#include <SFML/Graphics.hpp>

#ifndef PIANO_KEY_HPP
#define PIANO_KEY_CPP

class PianoKey {
    public:
        PianoKey();

        ~PianoKey();

        virtual void render(sf::RenderTarget& renderTarget);

    private:
        sf::RectangleShape rect;
};

#endif