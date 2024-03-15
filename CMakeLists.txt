cmake_minimum_required(VERSION 3.10)
project(cs-314-group-7-project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Google Test framework
add_subdirectory(libs/googletest-1.14.0)

# Add source files
add_subdirectory(code)

# Add tests
add_subdirectory(tests)
