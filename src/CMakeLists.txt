#############################################################################
# Name:        src/CMakeListst.txt
# Project:     ProjectStart: Run from taskbar to group project link files.
# Purpose:     CMake file to list source files.
# Author:      Nick Matthews
# Website:     https://github.com/nickmat/ProjectStart
# Created:     2nd January 2022
# Copyright:   (c) 2016, Nick Matthews
# Licence:     Boost Software License - Version 1.0
#############################################################################


set( SRC_FILES
    psApp.h
    psApp.cpp
    psFrame.h
    psFrame.cpp
)

if(WIN32)
    list(APPEND SRC_FILES psResource.rc)
endif()

add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES})

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
