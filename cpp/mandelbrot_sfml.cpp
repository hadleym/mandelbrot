#include <SFML/Graphics.hpp>
#include <complex>
#include <iostream>

// Function to calculate the Mandelbrot set
int mandelbrotSet(double x0, double y0, int maxIter) {
    std::complex<double> z(0, 0);
    std::complex<double> c(x0, y0);
    int iteration = 0;
    while (std::abs(z) < 2 && iteration < maxIter) {
        z = z * z + c;
        ++iteration;
    }
    return iteration;
}

int main(int argc, char* argv[]) {
    // Check if command-line arguments are provided
    if (argc != 8) {
        std::cerr << "Usage: " << argv[0] << " <xMin> <xMax> <yMin> <yMax> <width> <height> <maxIter>" << std::endl;
        return 1;
    }

    // Parse command-line arguments
    double xMin = std::stod(argv[1]);
    double xMax = std::stod(argv[2]);
    double yMin = std::stod(argv[3]);
    double yMax = std::stod(argv[4]);
    int width = std::stoi(argv[5]);
    int height = std::stoi(argv[6]);
    int maxIter = std::stoi(argv[7]);

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(width, height), "Mandelbrot Set");

    // Create SFML image
    sf::Image image;
    image.create(width, height);

    // Draw Mandelbrot set
    for (int py = 0; py < height; ++py) {
        for (int px = 0; px < width; ++px) {
            double x0 = xMin + (xMax - xMin) * px / (width - 1);
            double y0 = yMin + (yMax - yMin) * py / (height - 1);
            int iteration = mandelbrotSet(x0, y0, maxIter);
            sf::Color color(iteration % 256, iteration % 256, iteration % 256);
            image.setPixel(px, py, color);
        }
    }

    // Load SFML texture from image
    sf::Texture texture;
    texture.loadFromImage(image);

    // Create SFML sprite
    sf::Sprite sprite(texture);

    // Main loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear window
        window.clear();

        // Draw sprite
        window.draw(sprite);

        // Display window
        window.display();
    }

    return 0;
}

