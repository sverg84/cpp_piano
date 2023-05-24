#include <array>
#include <vector>
#include <SFML/Window/Keyboard.hpp>

#ifndef NAMESPACE_PIANO
#define NAMESPACE_PIANO

namespace piano {
    // Window
    constexpr int HEIGHT = 1600; // MacBook Pro M1 Retina height
    constexpr int WIDTH = 2560; // MackBook Pro M1 Retina width

    // Music notes
    constexpr int SAMPLE_RATE = 192000; // "CD quality"
    constexpr float MIDDLE_A_FREQUENCY = 440.0f; // A above "Middle C"

    enum SEMITONES_FROM_MIDDLE_A {
        C4 = -9,
        DFLAT4 = -8,
        D4 = -7,
        EFLAT4 = -6,
        E4 = -5,
        F4 = -4,
        GFLAT4 = -3,
        G4 = -2,
        AFLAT4 = -1,
        A4 = 0,
        BFLAT4 = 1,
        B4 = 2,
        C5 = 3,
        DFLAT5 = 4,
        D5 = 5,
        EFLAT5 = 6,
        E5 = 7,
        F5 = 8,
    };

    // Piano keys UI values
    constexpr float KEY_OUTLINE_THICKNESS = 3.0f;
    constexpr int NUM_BLACK_KEYS = 7;
    constexpr int NUM_WHITE_KEYS = 11; // length of QWERTY center row
    constexpr float KEY_WIDTH = 
        (piano::WIDTH - (piano::NUM_WHITE_KEYS * piano::KEY_OUTLINE_THICKNESS)) / piano::NUM_WHITE_KEYS;

    // Keyboard values for piano keys (left-to right)
    constexpr std::array<std::pair<sf::Keyboard::Key, SEMITONES_FROM_MIDDLE_A>, NUM_BLACK_KEYS> BLACK_KEYS {
        std::make_pair(sf::Keyboard::W, DFLAT4),
        std::make_pair(sf::Keyboard::E, EFLAT4),
        std::make_pair(sf::Keyboard::T, GFLAT4),
        std::make_pair(sf::Keyboard::Y, AFLAT4),
        std::make_pair(sf::Keyboard::U, BFLAT4),
        std::make_pair(sf::Keyboard::O, DFLAT5),
        std::make_pair(sf::Keyboard::P, EFLAT5)
    };
    constexpr std::array<std::pair<sf::Keyboard::Key, SEMITONES_FROM_MIDDLE_A>, NUM_WHITE_KEYS> WHITE_KEYS {
        std::make_pair(sf::Keyboard::A, C4),
        std::make_pair(sf::Keyboard::S, D4),
        std::make_pair(sf::Keyboard::D, E4),
        std::make_pair(sf::Keyboard::F, F4),
        std::make_pair(sf::Keyboard::G, G4),
        std::make_pair(sf::Keyboard::H, A4),
        std::make_pair(sf::Keyboard::J, B4),
        std::make_pair(sf::Keyboard::K, C5),
        std::make_pair(sf::Keyboard::L, D5),
        std::make_pair(sf::Keyboard::Semicolon, E5),
        std::make_pair(sf::Keyboard::Quote, F5)
    };
}

#endif
