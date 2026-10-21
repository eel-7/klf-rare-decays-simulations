# $Id: CMakeLists.txt 86065 2014-11-07 08:51:15Z gcosmo $

#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(plots)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
# option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
# if(WITH_GEANT4_UIVIS)
#   find_package(Geant4 REQUIRED ui_all vis_all)
# else()
#   find_package(Geant4 REQUIRED)
# endif()
if(NOT ROOT_FOUND)
# find_package(ROOT 6 REQUIRED)
    find_package(ROOT REQUIRED)
endif()
message(STATUS "[plots] ROOT_VERSION: ${ROOT_VERSION}")

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
# include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/src)


include_directories(${ROOT_INCLUDE_DIR})
link_directories(${ROOT_LIBRARY_DIR})

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/source/*.hpp)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable (controlPlots src/controlPlots.cpp ${sources} ${headers})
target_link_libraries(controlPlots ${ROOT_LIBRARIES})
# target_link_libraries(plots)


#----------------------------------------------------------------------------
# For internal Geant4 use - but has no effect if you build this
# example standalone
#
# add_custom_target(jlabk_exec DEPENDS jlabk)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS controlPlots DESTINATION bin)
