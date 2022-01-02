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


cmake_minimum_required(VERSION 3.22)

project(ProjectStart)

find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

# Setup the source files
add_subdirectory(src)

