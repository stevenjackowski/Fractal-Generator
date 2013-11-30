//
//  complex.h
//  Fractal Generator
//


#ifndef __Fractal_Generator__complex__
#define __Fractal_Generator__complex__

class Complex {
    double real;
    double imaginary;
    
public:
    Complex(): real(0), imaginary(0) {}
    Complex(const double& re, const double& im): real(re), imaginary(im) {}
    ~Complex() {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // calculate and return absolute value of the complex number
    double absVal() const;

    // calculate and return the square of the complex number
    Complex sqr() const;
    
    // overloaded + operator to support complex number addition
    friend Complex operator+(const Complex&, const Complex&);
};


#endif /* defined(__Fractal_Generator__complex__) */
