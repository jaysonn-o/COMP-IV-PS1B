// Copyright 2024 Jason Ossai

#ifndef _HOME_JASON_PS1B_PHOTOMAGIC_HPP_
#define _HOME_JASON_PS1B_PHOTOMAGIC_HPP_

#include <algorithm>  // C++ system header
#include <SFML/Graphics.hpp>  // C++ system header

#include "FibLFSR.hpp"  // Project header file

namespace PhotoMagic {
    // Transforms the image using FibLFSR
    void transform(sf::Image* image, FibLFSR* lfsr);  // Change to pointer
}

#endif  // _HOME_JASON_PS1B_PHOTOMAGIC_HPP_
