#include "../R2Lib/Vector2.h"
#include "../R2Lib/Matrix2.h"

#include "gtest/gtest.h"

TEST(MatrixVector_MultiplicationTest, MatrixVector_Test)
{
    Matrix2 M{
         1.0, -1.0,
        -2.0, 0.5
    };

    Vector2 v{ 1.0, -2.0 };

    const double vResultX = 3.0;
    const double vResultY = -3.0;

    v *= M;

    EXPECT_EQ(v.X(), vResultX);
    EXPECT_EQ(v.Y(), vResultY);
}