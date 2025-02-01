// Copyright 2024 Aadit Engineer

#include "FibLFSR.hpp"
#include <stdexcept>
#include <iostream>

FibLFSR::FibLFSR(const std::string initialSeed) {
    seed = initialSeed;

    if (initialSeed.length() != 16) {
        throw std::runtime_error("Seed length is not 16 bits");
    }

    for (char c : initialSeed) {
        if (c != '0' && c != '1') {
            throw std::runtime_error(
                "Invalid seed input; must be either '0' or '1'");
        }
    }
}

int FibLFSR::step() {
    int outputBit = seed[0] ^ seed[2] ^ seed[3] ^ seed[5];

    for (size_t i = 0; i < 15; i++) {
        seed[i] = seed[i + 1];
    }

    seed[15] = (outputBit == 0) ? '0' : '1';

    return outputBit;
}

int FibLFSR::generate(int k) {
    int result = 0;
    for (int i = 0; i < k; ++i) {
        result *= 2;
        result += step();
    }
    return result;
}

std::ostream& operator<<(std::ostream& output, const FibLFSR& fib) {
    output << fib.seed;
    return output;
}
