# This file is part of anyapp.
# See the LICENSE file for the software license.
# (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR})


set(TEST_SRC
    test_anyapp.cpp
)


add_executable(anyapp-test ${TEST_SRC})
target_link_libraries(anyapp-test gtest gtest_main pthread anyapplib ${CMAKE_REQUIRED_LIBRARIES})
gtest_add_tests(TARGET anyapp-test  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

