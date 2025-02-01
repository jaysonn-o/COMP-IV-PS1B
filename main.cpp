// Copyright 2024 Jason Ossai
#include <iostream>
#include "PhotoMagic.hpp"   //  Include directory for project headers
#include "FibLFSR.hpp"  //  Include directory for project headers

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0]
            << " input-file.png output-file.png LFSR-seed"
            << std::endl;  //  Break line to avoid exceeding 80 characters
        return 1;
    }

    //  Read command line arguments
    const std::string inputFile = argv[1];
    const std::string outputFile = argv[2];
    const std::string lfsrSeed = argv[3];

    //  Load the source image
    sf::Image image;
    if (!image.loadFromFile(inputFile)) {
        std::cerr << "Error loading image: " << inputFile << std::endl;
        return 1;
    }

    //  Display the original image
    sf::RenderWindow window1(sf::VideoMode(image.getSize().x,
        image.getSize().y),
        "Original Image");

    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

    //  Create and initialize FibLFSR with the seed
    FibLFSR lfsr(lfsrSeed);  // Assuming it accepts a seed

    //  Transform the image using the FibLFSR
    PhotoMagic::transform(&image, &lfsr);

    //  Display the transformed image
    sf::RenderWindow window2(sf::VideoMode(image.getSize().x,
        image.getSize().y),
        "Transformed Image");

    sf::Texture transformedTexture;
    transformedTexture.loadFromImage(image);
    sf::Sprite transformedSprite(transformedTexture);

    //  Event loop for both windows
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        window1.clear();
        window1.draw(sprite);
        window1.display();

        window2.clear();
        window2.draw(transformedSprite);
        window2.display();
    }

    //  Save the transformed image to disk
    if (!image.saveToFile(outputFile)) {
        std::cerr << "Error saving image: " << outputFile << std::endl;
        return 1;
    }

    return 0;
}
