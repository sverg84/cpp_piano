#include <cmath>
#include "../include/namespace_piano.hpp"
#include "../include/Note.hpp"

float semitone2frequency(const piano::SEMITONES_FROM_MIDDLE_A& semitone) {
    return piano::MIDDLE_A_FREQUENCY * std::pow(std::pow(2.0, 1.0 / 12.0), semitone);
}

Note::Note(const piano::SEMITONES_FROM_MIDDLE_A& semitone) {
    std::vector<sf::Int16> samples(piano::SAMPLE_RATE);

    float dist = piano::SAMPLE_RATE / semitone2frequency(semitone);
    int count = piano::SAMPLE_RATE / dist +1;

    for(int a = 0; a < count; a++)
    {
        for(int b = 0; b < dist; b++)
        {
            if(a * dist + b >= piano::SAMPLE_RATE)
            {
                break;
            }

            const int index = a * static_cast<int>(dist) + b;
            samples[index] = std::sin((b / dist * 360.f) * M_PI / 180) * INT16_MAX;
        }
    }

    buffer.loadFromSamples(samples.data(), samples.size(), 1, piano::SAMPLE_RATE);
    setBuffer(buffer);
}

Note::~Note(void) {}