# This file is part of anyapp.
# See the LICENSE file for the software license.
# (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com

include_directories(${CMAKE_SOURCE_DIR}/include)

set(ANYAPP_LIB_MOC
    ${CMAKE_SOURCE_DIR}/include/anyapp/anyapp.hpp
)
qt5_wrap_cpp(ANYAPP_LIB_MOC_CPP ${ANYAPP_LIB_MOC})

set(ANYAPP_LIB_SRC
    anyapp.cpp
)


add_library(anyapplib ${ANYAPP_LIB_SRC} ${ANYAPP_LIB_MOC_CPP})
target_link_libraries(anyapplib Qt5::Gui Qt5::Core ${CMAKE_REQUIRED_LIBRARIES})

