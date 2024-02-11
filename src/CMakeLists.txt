#############################################################################
# Name:        src/CMakeListst.txt
# Project:     ProjectStart: Run from taskbar to group project link files.
# Purpose:     CMake file to list source files.
# Author:      Nick Matthews
# Website:     https://github.com/nickmat/ProjectStart
# Created:     2nd January 2022
# Copyright:   (c) 2022..2024, Nick Matthews
# Licence:     Boost Software License - Version 1.0
#############################################################################


set( SRC_FILES
    psApp.cpp
    psFrame.cpp
    psVersion.cpp
)

set( HDR_FILES
    psApp.h
    psFrame.h
    psVersion.h
)


add_executable(${PROJECT_NAME} WIN32 ${SRC_FILES} ${HDR_FILES} psResource.rc)

# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} wx::core wx::base)
