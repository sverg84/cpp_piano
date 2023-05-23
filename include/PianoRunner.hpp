#include <SFML/Graphics.hpp>

#ifndef PIANO_RUNNER_HPP
#define PIANO_RUNNER_HPP


class PianoRunner {
    public:
        PianoRunner();

        virtual ~PianoRunner();

        virtual void run();

    private:
        sf::RenderWindow window;
};


#endif
