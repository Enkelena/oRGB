cmake_minimum_required(VERSION 3.5)
project(TrainingCpp)

# General
###############################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      /usr/local/share/cmake
                      /usr/share/cmake
  )

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

#-Wmissing-include-dirs
set(CMAKE_CXX_FLAGS 
    "-O2 \
    -pthread \
    -pedantic \
    -Wall \
    -Wextra \
    -Wcast-align \
    -Wdisabled-optimization \
    -Wformat=2 \
    -Winit-self \
    -Wlogical-op \
    -Wmissing-declarations \
    -Wnoexcept \
    -Woverloaded-virtual \
    -Wredundant-decls \
    -Wshadow \
    -Wsign-promo \
    -Wstrict-null-sentinel \
    -Wstrict-overflow=5 \
    -Wswitch-default \
    -Wundef \
    -Werror \
    -Wno-unused"
  )

# Find required packages
###############################################################################

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
#find_package(GTest REQUIRED)
#enable_testing()
#-Wcast-qual \
add_subdirectory(example_2)
