//
//  fractal.cpp
//  Fractal Generator
//

#include <algorithm>
#include <cmath>
#include <cstring> 
#include <iostream>

#include "complex.h"
#include "fractal.h"

using std::abs;     using std::log2;
using std::sqrt;

// generates a grid from -2 to 2 on both axes
Grid::Grid(std::size_t size): real_axis() {
    const double step = 4.0/((double)size-1.0);
    real_axis.reserve(size);
    real_axis.push_back(-2.0);
    for (std::size_t i = 0; i != size-1; i++) {
        real_axis.push_back(real_axis[i] + step);
    }
    imaginary_axis = real_axis;
}

// color normalization algorithm
double color(double& Zabs, int& last_iteration) {
    return last_iteration + 1.5 - log2(log2(Zabs));
}


// generate a mandelbrot fractal
void Fractal::generate_mandelbrot() {
    for (std::size_t i = 0; i != resolution; i++) {
        double real = grid.getRealAt(i);
        
        for (std::size_t j = 0; j != resolution; j++) {
            double im = grid.getImAt(j);
            Complex C(real, im);
            Complex Z(0, 0);
            int its = 0;
            while (Z.absVal() < 2 && its < max_iterations) {
                Z = Z.sqr() + C;
                its++;
            }
            double Zabs = Z.absVal();
            iteration_data[i*resolution + j] = color(Zabs, its);
        }
    }
}

void Fractal::generate_julia(Complex& C) {
    for (std::size_t i = 0; i != resolution; i++) {
        double real = grid.getRealAt(i);
        
        for (std::size_t j = 0; j != resolution; j++) {
            double im = grid.getImAt(j);
            Complex Z(real, im);
            int its = 0;
            while (Z.absVal() < 2 && its < max_iterations) {
                Z = Z.sqr() + C;
                its++;
            }
            double Zabs = Z.absVal();
            iteration_data[i*resolution + j] = color(Zabs, its);
        }
    }
}

void Fractal::generate_burning_ship() {
    for (std::size_t i = 0; i != resolution; i++) {
        double real = grid.getRealAt(i);
        
        for (std::size_t j = 0; j != resolution; j++) {
            double im = grid.getImAt(j);
            Complex C(real, im);
            Complex Z(0, 0);
            int its = 0;
            while (Z.absVal() < 2 && its < max_iterations) {
                // for a burning ship fractal, take the absolute value of each element before squaring
                Z = Complex(abs(Z.getReal()), abs(Z.getImaginary())).sqr() + C;
                its++;
            }
            double Zabs = Z.absVal();
            iteration_data[i*resolution + j] = color(Zabs, its);
        }
    }
}



