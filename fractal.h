//
//  fractal.h
//  Fractal Generator
//


#ifndef __Fractal_Generator__fractal__
#define __Fractal_Generator__fractal__

#include <cstring>
#include <vector>

#include "complex.h"

/* Grid: Class contains two vectors of doubles that hold axis data for the imaginary plane. 
 */
class Grid {
    std::vector<double> real_axis;
    std::vector<double> imaginary_axis;
    
public:
    Grid(std::size_t);
    
    // return the value at the given std::size_t location
    double getRealAt(std::size_t i) const { return real_axis[i]; }
    double getImAt(std::size_t j) const { return imaginary_axis[j]; }
    std::size_t size() const { return real_axis.size(); }
};


/* Fractal: Class that contains the data needed to represent a fractal */
class Fractal {
protected: 
    Grid grid;
    std::vector<int> iteration_data;
    const int max_iterations;
    const std::size_t resolution;
    
public:
    Fractal(): grid(0), max_iterations(0), resolution(0) {}
    Fractal(const std::size_t n, const int max_it): grid(n), max_iterations(max_it), resolution(n) {
        iteration_data.reserve(resolution*resolution);
    }
    
    void set(const std::size_t n, const int max_it) {
    }
    
    // use () operator to access iteration_data
    int operator()(const std::size_t i, const std::size_t j) const {
        return iteration_data[i*resolution + j];
    }
    
    std::size_t getRes() const { return resolution; }
    std::size_t getMaxIt() const { return max_iterations; }
    double getRealAt(std::size_t i) const { return grid.getRealAt(i); }
    double getImAt(std::size_t j) const { return grid.getImAt(j); }
    
    // generation functions
    void generate_mandelbrot();
    void generate_julia(Complex&);
    void generate_burning_ship();
};




#endif /* defined(__Fractal_Generator__fractal__) */
