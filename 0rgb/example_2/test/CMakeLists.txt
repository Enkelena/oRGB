# # Add Executable
# ###############################################################################

# add_executable( ${PROJECT_NAME}_test1
#   opencv_wrapper_test.cpp
# )


# # Link libraries
# ###############################################################################

# target_link_libraries( ${PROJECT_NAME}_test1
#   ${PROJECT_NAME}
#   ${OpenCV_LIBRARIES}
#   ${GTEST_BOTH_LIBRARIES}
#   -pthread
# )

# # Add Test 
# ################################################################################

# add_test(
#   NAME OpenCvWrapperTest
#   COMMAND ${PROJECT_NAME}_test1
# )