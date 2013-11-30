//
//  user_options.cpp
//  Fractal Generator
//
//  Created by Steven Jackowski on 11/29/13.
//  Copyright (c) 2013 Steven Jackowski. All rights reserved.
//

#include <iostream>
#include <string>

#include "complex.h"
#include "user_options.h"

using std::cin;         using std::cout;
using std::endl;        using std::string;



void user_options() {
    
    string fractal_type;
    do {
        // prompt user
        cout << "Please select a fractal type: mandelbrot, julia, or burning ship" << endl;
        getline(cin, fractal_type);
    } while (fractal_type != "mandelbrot" && fractal_type != "julia" && fractal_type != "burning ship");
    
    if (fractal_type == "julia") {
        // ask user to define C for the Julia set
        double c_real;
        do {
            cout << "Select a value for the real part of C:" << endl;
            cin >> c_real;
        } while (cin);
        
        double c_im;
        do {
            cout << "Select a value for the imaginary part of C:" << endl;
            cin >> c_im;
        } while (cin);
        Complex C(c_real, c_im);
        FRAC.generate_julia(C);
        
    } else if (fractal_type == "burning ship") {
        FRAC.generate_burning_ship();
        
    } else {
        FRAC.generate_mandelbrot();
    }
}
