# This file is part of anyapp.
# See the LICENSE file for the software license.
# (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com


include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set(ANYAPP_RCC
    anyapp.qrc
)
qt5_add_resources(ANYAPP_RES ${ANYAPP_RCC})


set(ANYAPP_UI
    mainwindow.ui
)
qt5_wrap_ui(ANYAPP_UI_H ${ANYAPP_UI})


set(ANYAPP_MOC
    mainwindow.hpp
)
qt5_wrap_cpp(ANYAPP_MOC_CPP ${ANYAPP_MOC})


set(ANYAPP_SRC
    main.cpp
    mainwindow.cpp
)


add_executable(anyapp ${ANYAPP_SRC} ${ANYAPP_MOC_CPP} ${ANYAPP_RES} ${ANYAPP_UI_H})
target_link_libraries(anyapp anyapplib ${CMAKE_REQUIRED_LIBRARIES} Qt5::Core Qt5::Widgets)
install(TARGETS anyapp RUNTIME DESTINATION bin)

