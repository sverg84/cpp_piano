#include <SFML/Graphics.hpp>

#ifndef PIANO_KEY_HPP
#define PIANO_KEY_HPP

class PianoKey {
    public:
        PianoKey(
            const float& keyWidth,
            const float& positionX,
            const sf::Keyboard::Key& key,
            const sf::Color& color
        );

        virtual ~PianoKey();

        virtual void render(sf::RenderTarget& renderTarget);

        virtual const sf::Vector2f& getPosition();

        virtual const sf::Vector2f& getSize();

    protected:
        sf::RectangleShape rect;

    private:
        sf::Keyboard::Key key = sf::Keyboard::Unknown;
};

#endif