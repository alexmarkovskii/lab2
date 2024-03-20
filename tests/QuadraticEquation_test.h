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

TEST(Quadratictest, two_roots){
    ASSERT_EQ(solveQuadraticEquation(1, 4, -5)[0], -5);
    ASSERT_EQ(solveQuadraticEquation(1, 4, -5)[1], 1);
}

TEST(Quadratictest, one_root){
    ASSERT_EQ(solveQuadraticEquation(1, -6, 9)[0], 3);
    ASSERT_EQ(solveQuadraticEquation(1, -6, 9)[1], 3);
}

TEST(Quadratictest, float_root){
    ASSERT_EQ(solveQuadraticEquation(4, 6, 2)[0], -1);
    ASSERT_EQ(solveQuadraticEquation(4, 6, 2)[1], -0.5);
}

TEST(Quadratictest, zero_discriminant){
    ASSERT_EQ(solveQuadraticEquation(4, -5, 0)[0], 0);
    ASSERT_EQ(solveQuadraticEquation(4, -5, 0)[1], 1.25);
}

TEST(Quadratictest, nan_roots){
    ASSERT_TRUE(isnan(solveQuadraticEquation(4, 2, 4)[0]));
    ASSERT_TRUE(isnan(solveQuadraticEquation(4, 2, 4)[1]));
}

TEST(Quadratictest, invalid_vars){
    ASSERT_TRUE(isnan(solveQuadraticEquation(0, -5, 4)[0]));
    ASSERT_TRUE(isnan(solveQuadraticEquation(0, -5, 4)[0]));
}


#endif // QUADRATICEQUATION_TEST_H
