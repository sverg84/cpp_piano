#include <getopt.h>
#include <iostream>
#include "include/namespace_piano.hpp"
#include "include/PianoRunner.hpp"

const option longopts[] {
    {"num-keys", optional_argument, 0, 'n'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0},
};

void printHelp() {
    std::cout << "virtual piano (WIP) :o\n"
        << "Usage:\n"
        << "make && ./main [--num-keys <int>] [--help]\n\n"
        << "Arguments:\n"
        << "--num-keys <int> (-n <int>):\tSpecify the number of white piano keys to render.\n"
        << "\t\t\t\t(Defaults to rendering 8 white keys if not specified)\n"
        << "--help (-h):\t\t\tPrint this message and exit." << std::endl;
}

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
                printHelp();
                return 0;
            default:
                break;
        }
    }

    PianoRunner runner;
    runner.run();

    return 0;
}