# oRGB color space

The  recent  interest  in  automatic  image  manipulation  techniques such  as  color  harmonization,  color  transfer,  colorization,  as  wellas the proliferation of work in computational photography, suggest the need for an intuitive, yet simple and practical computational computer graphics color space. This is where oRGB comes to the play: A Practical Opponent Color Space for Computer Graphics. We present a new color model, oRGB, that is based on opponentcolor theory.

## How does it work 

RGBis a simple R′G′B′-based color space that is useful for computational applications, such as color adjustment, color transformation, and color transfer.  It retains the notions of hue and saturation presented in HSV, but adds a non-linear perceptual brightness (similar toHSB). Unlike HSV/HSB, it encodes perceptualcolor opponency and its axes encode common color naming used by people. It also provides a natural computational framework for categorizing a color by its color temperature - i.e.warm  vs.  cool.   Finally,  the  simplicity  of  the  intermediate  space L′C′C′ allows for straightforward gamut mapping that is critical for computational applications where the manipulations of colors often produces out-of-gamut results.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

What things you need to install the software and how to install them

* [OpenCV](https://opencv.org/) : Open Source Computer Vision Library.
* [Eigen](https://gitlab.com/libeigen/eigen) :  C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.
* [GoogleTest](https://github.com/google/googletest) : Google Test is a unit testing library for the C++ programming language, based on the xUnit architecture. 
* [Doxygen](http://www.doxygen.nl/) : Doxygen is the de facto standard tool for generating documentation from annotated C++ sources.


## Installing

A step by step series of examples that tell you how to get a development env running

### Installing OpenCV library

Required packages

```
GCC 4.4.x or later
CMake 2.8.7 or higher
Git
GTK+2.x or higher, including headers (libgtk2.0-dev)
pkg-config
Python 2.6 or later and Numpy 1.5 or later with developer packages (python-dev, python-numpy)
ffmpeg or libav development packages: libavcodec-dev, libavformat-dev, libswscale-dev
```

Getting the Cutting-edge OpenCV from the Git Repository
```
cd ~/<my_working_directory>
git clone https://github.com/opencv/opencv.git
```

Build. From build directory execute make, it is recommended to do this in several threads

```
make -j4 # runs 4 jobs in parallel
```
### Installing Eigen library
Eigen doesn't have any dependencies other than the C++ standard library. 
```
cd ~/<my_working_directory>
git clone https://gitlab.com/libeigen/eigen.git
```

### Installing Google test libray

Requirments
```
* Bazel or Cmake
* a C++11-standard-compliant compiler
```
Cloning
```
git clone https://github.com/google/googletest.git
```

### Installing Doxygen for documentation

Cloning
```
git clone https://github.com/doxygen/doxygen.git
cd doxygen
```
After that you can use
```
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
```
After the binaries have been built, you can use
```
make install
```

### Download our code
Now download the actual code from this same repository
```
git clone git@github.com:Enkelena/oRGB.git
```
On the main.cpp, line 13 where the path is written, please put the path of an image of your own
Use cmake to build this project.
## Authors

* **Enkelena H** 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Mergim Halimi, Edison Telaku

