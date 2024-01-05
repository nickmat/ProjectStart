#############################################################################
# Name:        CMakeListst.txt
# Project:     ProjectStart: Run from taskbar to group project link files.
# Purpose:     CMake file to create wxWidgets program.
# Author:      Nick Matthews
# Website:     https://github.com/nickmat/ProjectStart
# Created:     2nd January 2022
# Copyright:   (c) 2016, Nick Matthews
# Licence:     Boost Software License - Version 1.0
#############################################################################


cmake_minimum_required(VERSION 3.25)

project(ProjectStart)

#find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)
option( BUILD_SHARED_LIBS "Set static libs" OFF )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED On )

# Setup the source files
add_subdirectory( 3rdparty/wxWidgets )
add_subdirectory( src )

