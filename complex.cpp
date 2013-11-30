//
//  complex.cpp
//  Fractal Generator
//

#include <cmath>
#include "complex.h"

double Complex::absVal() const {
    return std::sqrt(real*real + imaginary*imaginary);
}

Complex Complex::sqr() const {
    double re_part = real*real - imaginary*imaginary;
    double im_part = 2*(imaginary*real);
    return Complex(re_part, im_part);
}

Complex operator+(const Complex& comp1, const Complex& comp2) {
    double re1 = comp1.real;
    double re2 = comp2.real;
    double im1 = comp1.imaginary;
    double im2 = comp2.imaginary;
    return Complex(re1 + re2, im1 + im2);
}
