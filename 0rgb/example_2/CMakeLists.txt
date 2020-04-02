project(colorspace)

# Include directories
###############################################################################

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${GTEST_INCLUDE_DIRS}
  include/
)

# Libraries
###############################################################################

add_library( ${PROJECT_NAME}
  src/colorspaceadjustment.cpp
  src/inversecolorpsaceadjustement.cpp
)

# Executables
###############################################################################

add_executable( ${PROJECT_NAME}_exec
  src/main.cpp
)

# Link libraries
###############################################################################

target_link_libraries( ${PROJECT_NAME}_exec
  ${PROJECT_NAME}
  ${OpenCV_LIBRARIES}
)

# Testing
###############################################################################

enable_testing()

add_subdirectory(test)