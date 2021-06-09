project(R2Lib)

set(R2Lib_Src
	Matrix2.h
	Matrix2.cpp
	Vector2.h
	Vector2.cpp
	VectorUtils.h
)

add_library(${PROJECT_NAME} ${R2Lib_Src})