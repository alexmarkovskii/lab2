#include "QuadraticEquation.h"
#include "math.h"
#include <stdlib.h>

void solveQuadraticEquation(double* roots, double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (a==0){
        roots[0] = NAN;
        roots[1] = NAN;
    } else if (discriminant > 0) {
        roots[0] = (-b - sqrt(discriminant)) / (2 * a);
        roots[1] = (-b + sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
        roots[1] = -b / (2 * a);
    } else {
        roots[0] = NAN;
        roots[1] = NAN;
    }

}
