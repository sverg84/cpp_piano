#include <SFML/Graphics.hpp>
#include "Note.hpp"

#ifndef PIANO_KEY_HPP
#define PIANO_KEY_HPP

class PianoKey {
    public:
        PianoKey(
            const float& positionX,
            const sf::Keyboard::Key& key,
            const piano::SEMITONES_FROM_MIDDLE_A& semitone,
            const sf::Color& color
        );

        virtual ~PianoKey();

        const sf::Vector2f& getPosition();

        void render(sf::RenderTarget& renderTarget);

    protected:
        sf::RectangleShape rect;

    private:
        sf::Keyboard::Key key = sf::Keyboard::Unknown;
        sf::Color color;
        Note note;
};

#endif