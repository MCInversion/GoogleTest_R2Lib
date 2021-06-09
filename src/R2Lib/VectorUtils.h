//#include <cmath>
//#include <memory>

#pragma once

/// dim values to avoid magic numbers
constexpr size_t GEOMETRY_DIMENSION2 = 2;
constexpr size_t GEOMETRY_DIMENSION_2x2 = 4;

// tolerance
constexpr double COORD_TOLERANCE = 1e-5;
constexpr double PRODUCT_TOLERANCE = 1e-4;

enum eCoordID
{
	  X_COORD //!<X coordinate id
	, Y_COORD //!<Y coordinate id
};

enum e2x2_MatrixCoordID
{
	MAT2_11 = 0, MAT2_12 = 1,
	MAT2_21 = 2, MAT2_22 = 3
};