#include "R2Lib/Matrix2.h"
#include "R2Lib/Vector2.h"

#include <iostream>
#include <cassert>

void MatrixVectorMultTest()
{
    Matrix2 M{
	     1.0, -1.0,
	    -2.0, 0.5
    };

    Vector2 v{ 1.0, -2.0 };

    const double vResultX = 1.0;
    const double vResultY = -3.0;

    v *= M;

    assert(v.X() == vResultX);
    assert(v.Y() == vResultY);
    std::cout << "v = (" << v.X() << ", " << v.Y() << ")\n";
}

int main(int argc, char* argv[])
{
    //MatrixVectorMultTest();
    // other stuff in main
}


