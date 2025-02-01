#include "PhotoMagic.hpp"  // Include the directory for the header file
#include "FibLFSR.hpp"     // Include the directory for the FibLFSR header

namespace PhotoMagic {

    // Transforms image using FibLFSR
    void transform(sf::Image* image, FibLFSR* lfsr) {
        // Get image dimensions
        unsigned int width = image->getSize().x;
        unsigned int height = image->getSize().y;

        for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                // Get the original pixel color
                sf::Color pixelColor = image->getPixel(x, y);

                // Generate 8-bit keys for red, green, and blue components
                uint8_t rKey = lfsr->generate(8);  // Generate 8 bits for red
                uint8_t gKey = lfsr->generate(8);  // Generate 8 bits for green
                uint8_t bKey = lfsr->generate(8);  // Generate 8 bits for blue

                // XOR the pixel components with the generated keys
                uint8_t newR = pixelColor.r ^ rKey;
                uint8_t newG = pixelColor.g ^ gKey;
                uint8_t newB = pixelColor.b ^ bKey;

                // Set the new pixel color
                sf::Color newColor(newR, newG, newB);
                image->setPixel(x, y, newColor);
            }
        }
    }

}  // namespace PhotoMagic