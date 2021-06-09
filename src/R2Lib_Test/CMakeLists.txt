cmake_minimum_required(VERSION 3.14)

project(R2Lib_Test VERSION 1.0)

# link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} MatrixVector_Test.cpp)
target_link_libraries(${PROJECT_NAME}
	R2Lib
	gtest_main
)

add_test(NAME MatrixVector_Test COMMAND ${PROJECT_NAME})

# post build command
add_custom_command(
     TARGET ${PROJECT_NAME}  
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND ${PROJECT_NAME}
)