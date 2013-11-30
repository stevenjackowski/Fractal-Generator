//
//  main.cpp
//  Fractal Generator
//

#include <GLUT/GLUT.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#include <cmath>

#include "complex.h"
#include "fractal.h"
#include "user_options.h"

/* Generate a global fractal:
    This needs to be global as glutDisplayFunc takes only a function without any arguments */
Fractal FRAC(2000, 50);

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void drawFractal() {
    glClear(GL_COLOR_BUFFER_BIT);
    //Mandelbrot frac(2000, 200);
    
    glBegin(GL_POINTS);
    glDisable(GL_POINT_SMOOTH);
    for (std::size_t i = 0; i != FRAC.getRes(); i++) {
        for (std::size_t j = 0; j != FRAC.getRes(); j++) {
            double maxit = FRAC.getMaxIt();
            double color = (FRAC(i, j)/maxit);
            glColor3f(0.0f, color, color);
            glVertex2f(FRAC.getRealAt(i), FRAC.getImAt(j));
            //glDrawPixels(
        }
    }
    glEnd();
    glFlush();
    
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    user_options();
    
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(700, 700);   // Set the window's initial width & height
    glutInitWindowPosition(250, 250); // Position the window's initial top-left corner
    glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
    
    glutDisplayFunc(drawFractal);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    

    
    glutMainLoop();                 // Enter the event-processing loop

    
    return 0;
}

