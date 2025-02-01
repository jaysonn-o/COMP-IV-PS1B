// Copyright 2024 Aadit Engineer
#ifndef _HOME_JASON_PS1B_FIBLFSR_HPP_
#define _HOME_JASON_PS1B_FIBLFSR_HPP_
#include <iostream>
#include <string>

    class FibLFSR {
    public:
        explicit FibLFSR(const std::string seed);

        int step();
        int generate(int k);

        friend std::ostream& operator<<(std::ostream& out, const FibLFSR& fib);

    private:
        std::string seed;
        int tap;
    };

// Two spaces before the comment to follow the style guide
std::ostream& operator<<(std::ostream& out, const FibLFSR& fib);

#endif  // _HOME_JASON_PS1B_FIBLFSR_HPP_
