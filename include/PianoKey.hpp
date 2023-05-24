#include <SFML/Graphics.hpp>

#ifndef PIANO_KEY_HPP
#define PIANO_KEY_CPP

class PianoKey {
    public:
        PianoKey(const float& keyWidth, const float& positionX);

        virtual ~PianoKey();

        virtual void render(sf::RenderTarget& renderTarget);

    private:
        sf::RectangleShape rect;
};

#endif