#include <iostream>
#include <complex>

int mandelbrot(std::complex<float> coord) {
    std::complex<float> z = 0;
    int i{0};
    while (std::abs(z) <= 2 && i < 10) {
        z = z*z + coord;
        i++;
    }
    return i;
}

std::string to_char(int val) {
    std::string output;
    if (val == 1) {
        output = "\033[1;35m█";
    } else if (val == 2) {
        output = "\033[1;34m█";
    } else if (val == 3) {
        output = "\033[1;32m█";
    } else if (val < 10) {
        output = "\033[1;33m█";
    } else if (val == 10) {
        output = "\033[1;31m█";
    } else {
        std::cout << "fuck";
    }
    return output;
}

int main() {
    int width, height;
    std::cout << "Width? " << std::endl;
    std::cin >> width;
    std::cout << "Height? " << std::endl;
    std::cin >> height;

    for (int i{1}; i <= height; i++) {
        for (int j{1}; j <= width; j++) {
            
            float re = 5.0 * (j - 1 - width/2) / width;
            float im = 5.0 * (i - 1 - height/2) / height;
            std::complex<float> coord = std::complex<float>(re, im);
            float val = mandelbrot(coord);
            std::cout << to_char(val);
            
            if (j == width) {
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
