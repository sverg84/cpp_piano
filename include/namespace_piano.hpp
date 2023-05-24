#include <array>
#include <vector>
#include <SFML/Window/Keyboard.hpp>

#ifndef NAMESPACE_PIANO
#define NAMESPACE_PIANO

namespace piano {
    const float KEY_OUTLINE_THICKNESS = 3.0f;
    const int NUM_BLACK_KEYS = 7;
    const int NUM_WHITE_KEYS = 11; // length of QWERTY center row
    const int HEIGHT = 1600; // MacBook Pro M1 Retina height
    const int WIDTH = 2560; // MackBook Pro M1 Retina width

    const std::array<sf::Keyboard::Key, NUM_BLACK_KEYS> BLACK_KEYS {
        sf::Keyboard::W,
        sf::Keyboard::E,
        sf::Keyboard::T,
        sf::Keyboard::Y,
        sf::Keyboard::U,
        sf::Keyboard::O,
        sf::Keyboard::P,
    };

    const std::array<sf::Keyboard::Key, NUM_WHITE_KEYS> WHITE_KEYS {
        sf::Keyboard::A,
        sf::Keyboard::S,
        sf::Keyboard::D,
        sf::Keyboard::F,
        sf::Keyboard::G,
        sf::Keyboard::H,
        sf::Keyboard::J,
        sf::Keyboard::K,
        sf::Keyboard::L,
        sf::Keyboard::Semicolon,
        sf::Keyboard::Quote,
    };
}

#endif
