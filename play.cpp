#include <getopt.h>
#include <iostream>
#include "include/namespace_piano.hpp"
#include "include/PianoRunner.hpp"

const option longopts[] {
    {"num-keys", optional_argument, 0, 'n'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0},
};

int main(int argc, char** argv) {
    int numKeys = piano::NUM_KEYS_DEFAULT;

    while (true) {
        int optionIndex = 0;
        const int opt = getopt_long(argc, argv, "n:h", longopts, &optionIndex);

        // exit condition for getopt_long
        if (opt == -1)
            break;

        // either set argument-specified number of keys
        // or print help message and exit, or continue
        switch (opt) {
            case 'n':
                numKeys = std::stoi(optarg);
                break;
            case 'h':
                std::cout << "help" << std::endl;
                return 0;
            default:
                break;
        }
    }

    PianoRunner runner;
    runner.run();

    return 0;
}