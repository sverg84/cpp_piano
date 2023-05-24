#include <memory>
#include "Piano.hpp"

#ifndef PIANO_RUNNER_HPP
#define PIANO_RUNNER_HPP


class PianoRunner {
    public:
        PianoRunner();

        virtual ~PianoRunner();

        void run();

    private:
        sf::RenderWindow window;

        Piano piano;

        struct PianoRunnerInternals;
        std::unique_ptr<PianoRunnerInternals> ptr;

        bool isInFocus = false;
};


#endif
