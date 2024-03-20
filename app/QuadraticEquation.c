#include "QuadraticEquation.h"
#include "math.h"

double* solveQuadraticEquation(double a, double b, double c) {
    static double result[2];
    double discriminant = b * b - 4 * a * c;

    if (a==0){
        result[0] = NAN;
        result[1] = NAN;
    } else if (discriminant > 0) {
        result[0] = (-b - sqrt(discriminant)) / (2 * a);
        result[1] = (-b + sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        result[0] = -b / (2 * a);
        result[1] = -b / (2 * a);
    } else {
        // Корни не являются действительными числами
        result[0] = NAN;
        result[1] = NAN;
    }

    return result;
}
