#ifndef QUADRATICEQUATION_TEST_H
#define QUADRATICEQUATION_TEST_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

extern "C" {
#include "QuadraticEquation.h"
}

double roots[2];

TEST(Quadratictest, two_roots){
    solveQuadraticEquation(roots, 1, 4, -5);
    ASSERT_EQ(roots[0], -5);
    ASSERT_EQ(roots[1], 1);
}

TEST(Quadratictest, one_root){
    solveQuadraticEquation(roots, 1, -6, 9);
    ASSERT_EQ(roots[0], 3);
    ASSERT_EQ(roots[1], 3);
}

TEST(Quadratictest, float_root){
    solveQuadraticEquation(roots, 4, 6, 2);
    ASSERT_EQ(roots[0], -1);
    ASSERT_EQ(roots[1], -0.5);
}

TEST(Quadratictest, zero_discriminant){
    solveQuadraticEquation(roots, 4, -5, 0);
    ASSERT_EQ(roots[0], 0);
    ASSERT_EQ(roots[1], 1.25);
}

TEST(Quadratictest, nan_roots){
    solveQuadraticEquation(roots, 4, 2, 4);
    ASSERT_TRUE(isnan(roots[0]));
    ASSERT_TRUE(isnan(roots[1]));
}

TEST(Quadratictest, invalid_vars){
    solveQuadraticEquation(roots, 0, -5, 4);
    ASSERT_TRUE(isnan(roots[0]));
    ASSERT_TRUE(isnan(roots[1]));
}


#endif // QUADRATICEQUATION_TEST_H
