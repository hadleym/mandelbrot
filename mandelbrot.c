#include <iostream>
#include <fstream>
#include <string>
#include <complex>
#include <stdexcept>

void mandelbrotSet(const std::string& filename, double xMin, double xMax, double yMin, double yMax, int width, int height, int maxIter) {
    std::ofstream imageFile(filename, std::ios::binary);
    if (!imageFile) {
        throw std::runtime_error("Error: Could not create file " + filename);
    }

    imageFile << "P6\n" << width << " " << height << "\n255\n";

    for (int py = 0; py < height; ++py) {
        for (int px = 0; px < width; ++px) {
            double x0 = xMin + (xMax - xMin) * px / (width - 1);
            double y0 = yMin + (yMax - yMin) * py / (height - 1);
            std::complex<double> z(0, 0);
            std::complex<double> c(x0, y0);
            int iteration = 0;
            while (std::abs(z) < 2 && iteration < maxIter) {
                z = z * z + c;
                ++iteration;
            }
            unsigned char color = iteration == maxIter ? 0 : static_cast<unsigned char>(255 * iteration / maxIter);
            imageFile << color << color << color;
        }
    }

    std::cout << "Mandelbrot set image created: " << filename << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 9) {
        std::cerr << "Usage: " << argv[0] << " <filename> <xMin> <xMax> <yMin> <yMax> <width> <height> <maxIter>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    double xMin = std::stod(argv[2]);
    double xMax = std::stod(argv[3]);
    double yMin = std::stod(argv[4]);
    double yMax = std::stod(argv[5]);
    int width = std::stoi(argv[6]);
    int height = std::stoi(argv[7]);
    int maxIter = std::stoi(argv[8]);

    try {
        mandelbrotSet(filename, xMin, xMax, yMin, yMax, width, height, maxIter);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

