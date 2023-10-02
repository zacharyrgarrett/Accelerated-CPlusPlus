cmake_minimum_required(VERSION 3.10) # Specify the minimum version for CMake

project(Accelerated-CPlusPlus VERSION 1.0) # Specify your project's name and version

set(CMAKE_CXX_STANDARD 11) # Specify the C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

# List your source files here
add_subdirectory(Ch0-GettingStarted)
add_subdirectory(Ch1-WorkingWithStrings)
add_subdirectory(Ch3-WorkingWithBatchesOfData)
add_subdirectory(Ch4-OrganizingProgramsAndData)
