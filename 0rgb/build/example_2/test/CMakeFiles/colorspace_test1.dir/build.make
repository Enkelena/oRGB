# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/solaborate/oRGB/0rgb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/solaborate/oRGB/0rgb/build

# Include any dependencies generated for this target.
include example_2/test/CMakeFiles/colorspace_test1.dir/depend.make

# Include the progress variables for this target.
include example_2/test/CMakeFiles/colorspace_test1.dir/progress.make

# Include the compile flags for this target's objects.
include example_2/test/CMakeFiles/colorspace_test1.dir/flags.make

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o: example_2/test/CMakeFiles/colorspace_test1.dir/flags.make
example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o: ../example_2/test/opencv_wrapper_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solaborate/oRGB/0rgb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o"
	cd /home/solaborate/oRGB/0rgb/build/example_2/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o -c /home/solaborate/oRGB/0rgb/example_2/test/opencv_wrapper_test.cpp

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.i"
	cd /home/solaborate/oRGB/0rgb/build/example_2/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solaborate/oRGB/0rgb/example_2/test/opencv_wrapper_test.cpp > CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.i

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.s"
	cd /home/solaborate/oRGB/0rgb/build/example_2/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solaborate/oRGB/0rgb/example_2/test/opencv_wrapper_test.cpp -o CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.s

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.requires:

.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.requires

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.provides: example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.requires
	$(MAKE) -f example_2/test/CMakeFiles/colorspace_test1.dir/build.make example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.provides.build
.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.provides

example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.provides.build: example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o


# Object files for target colorspace_test1
colorspace_test1_OBJECTS = \
"CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o"

# External object files for target colorspace_test1
colorspace_test1_EXTERNAL_OBJECTS =

example_2/test/colorspace_test1: example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o
example_2/test/colorspace_test1: example_2/test/CMakeFiles/colorspace_test1.dir/build.make
example_2/test/colorspace_test1: example_2/libcolorspace.a
example_2/test/colorspace_test1: /usr/local/lib/libopencv_dnn.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_gapi.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_highgui.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_ml.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_objdetect.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_photo.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_stitching.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_video.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_videoio.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_imgcodecs.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_calib3d.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_features2d.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_flann.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_imgproc.so.4.2.0
example_2/test/colorspace_test1: /usr/local/lib/libopencv_core.so.4.2.0
example_2/test/colorspace_test1: example_2/test/CMakeFiles/colorspace_test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/solaborate/oRGB/0rgb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable colorspace_test1"
	cd /home/solaborate/oRGB/0rgb/build/example_2/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/colorspace_test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
example_2/test/CMakeFiles/colorspace_test1.dir/build: example_2/test/colorspace_test1

.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/build

example_2/test/CMakeFiles/colorspace_test1.dir/requires: example_2/test/CMakeFiles/colorspace_test1.dir/opencv_wrapper_test.cpp.o.requires

.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/requires

example_2/test/CMakeFiles/colorspace_test1.dir/clean:
	cd /home/solaborate/oRGB/0rgb/build/example_2/test && $(CMAKE_COMMAND) -P CMakeFiles/colorspace_test1.dir/cmake_clean.cmake
.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/clean

example_2/test/CMakeFiles/colorspace_test1.dir/depend:
	cd /home/solaborate/oRGB/0rgb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/solaborate/oRGB/0rgb /home/solaborate/oRGB/0rgb/example_2/test /home/solaborate/oRGB/0rgb/build /home/solaborate/oRGB/0rgb/build/example_2/test /home/solaborate/oRGB/0rgb/build/example_2/test/CMakeFiles/colorspace_test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : example_2/test/CMakeFiles/colorspace_test1.dir/depend

