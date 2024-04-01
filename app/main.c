#include <stdio.h>
#include <stdlib.h>

#include "QuadraticEquation.h"

int main()
{
    printf("Hello World!\n");
    double roots[2];
    solveQuadraticEquation(roots, 1, 4, -5);

    printf("%f %f", roots[0], roots[1]);
}
