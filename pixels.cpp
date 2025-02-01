// Copyright 2024 Jason Ossai
// pixels.cpp: Using SFML to load a file, manipulate its pixels,
// and write it to disk

// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    sf::Image image;
    if (!image.loadFromFile("cat.jpg")) {
        return -1;
    }

    // p is a pixel from the image
    sf::Color p;

    // Create photographic negative of the upper-left 200px square
    for (int x = 0; x < 200; x++) {
        for (int y = 0; y < 200; y++) {
            p = image.getPixel(x, y);
            p.r = 255 - p.r;
            p.g = 255 - p.g;
            p.b = 255 - p.b;
            image.setPixel(x, y, p);
        }
    }

    sf::Vector2u size = image.getSize();
    sf::RenderWindow window(sf::VideoMode(size.x, size.y),
        "Meow");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    // Saving a PNG might cause a segmentation fault,
    // but the file will be written
    if (!image.saveToFile("cat-out.bmp")) {
        return -1;
    }

    return 0;
}
