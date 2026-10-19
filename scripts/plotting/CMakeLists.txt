# cmakelists for plots for mphys project
# plots
cmake_minimum_required(VERSION 3.20)
project(plots VERSION 1.0)

include(GNUInstallDirs)

if(PROJECT_IS_TOP_LEVEL AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "" FORCE)
    message(STATUS "[plots] CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
endif()
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "" FORCE)
#     message(STATUS "[plots] CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
# endif()

# find_program(CCACHE_FOUND ccache)
# if(CCACHE_FOUND)
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
# endif()

# SOURCES
file(GLOB_RECURSE SOURCES
    LIST_DIRECTORIES false
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    src/*.cpp src/*.h src/*.hpp src/*.inc
)

# if(NOT ROOT_FOUND)
# find_package(ROOT 6 REQUIRED)
find_package(ROOT REQUIRED)
# endif()
message(STATUS "[plots] ROOT_VERSION: ${ROOT_VERSION}")

include_directories(${ROOT_INCLUDE_DIR})
link_directories(${ROOT_LIBRARY_DIR})

# target_include_directories(plots SYSTEM PUBLIC ${ROOT_INCLUDE_DIRS})
# target_include_directories(plots PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
#     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )

# EXECUTABLE
add_executable(controlPlots src/controlPlots.cpp)
set_target_properties(controlPlots PROPERTIES OUTPUT_NAME controlPlots)

target_include_directories(controlPlots SYSTEM PUBLIC ${ROOT_INCLUDE_DIRS})
target_include_directories(controlPlots PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(controlPlots PUBLIC ${ROOT_LIBRARIES})
# target_link_libraries(plots)
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
install(TARGETS controlPlots DESTINATION bin)

#-------------------------------------------------------------------
# plots for report
# cmake_minimum_required(VERSION 3.20)
# project(plots VERSION 1.0)
# include(GNUInstallDirs)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)
# # set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -Wno-old-style-cast -DDEBUG")
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -Wno-old-style-cast")
#
# if(PROJECT_IS_TOP_LEVEL AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
#     set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "" FORCE)
#     message(STATUS "[plots] CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
# endif()
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "" FORCE)
#     message(STATUS "[plots] CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
# endif()
#
# find_program(CCACHE_FOUND ccache)
# if(CCACHE_FOUND)
#    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
# endif()
#
# # SOURCES
# file(GLOB_RECURSE SOURCES
#     LIST_DIRECTORIES false
#     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
#     src/*.cpp src/*.h src/*.hpp src/*.inc
# )
#
# # Create a shared library target named mu3eValLib using the collected source files
# add_library(plotsLib SHARED ${SOURCES})
#
# # Create an alias target for mu3eValLib named ana::comba for easier referencing
# add_library(klf::plots ALIAS plotsLib)
#
# # Set properties for the mu3eValLib target
# set_target_properties(plotsLib PROPERTIES
#     EXPORT_NAME plots     # Export name used for installation and export
#     OUTPUT_NAME plots     # Name of the output library file (.so file)
#     LINKER_LANGUAGE CXX
# )
#
# # find_package(nlohmann_json 3.11.0 REQUIRED)
#
# if(NOT ROOT_FOUND)
#     find_package(ROOT 6 REQUIRED)
# endif()
# message(STATUS "[plots] ROOT_VERSION: ${ROOT_VERSION}")
#
# # target_link_libraries(mu3eValLib PUBLIC ${ROOT_LIBRARIES} ROOT::GenVector mu3e::tools gttf::lib)
# target_link_libraries(plotsLib PUBLIC ${ROOT_LIBRARIES} ROOT::GenVector )
#
# target_include_directories(plotsLib SYSTEM PUBLIC ${ROOT_INCLUDE_DIRS})
# target_include_directories(plotsLib PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
#     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )
#
# # EXECUTABLE
# add_executable(controlPlots src/controlPlots.cpp)
# set_target_properties(controlPlots PROPERTIES OUTPUT_NAME controlPlots)
# # target_link_libraries(controlPlots PRIVATE mu3e::reportPlots nlohmann_json::nlohmann_json)
# target_link_libraries(controlPlots PRIVATE klf::plots)
# install(TARGETS controlPlots)
#
#
# # headers
# install(
#     DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/
#     FILES_MATCHING PATTERN *.h PATTERN *.hpp PATTERN *.inc PATTERN *.cuh
# )
#
# # targets
# install(TARGETS plotsLib EXPORT controlPlots-targets)
# install(EXPORT plots-targets
#     NAMESPACE klf::
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/controlPlots
# )

# set(SOURCES
#     src/*.cpp
#     src/*.hpp
# )
#
# find_package( ROOT COMPONENTS Hist Graf Gpad RIO Core MathCore Postscript )
#
# add_library(HistoCompare SHARED
#     ${SOURCES}
# )
#
# ####################
# target_link_libraries(HistoCompare PUBLIC ROOT::Core ROOT::Graf ROOT::Hist ROOT::Gpad)
# ####################
#
# target_include_directories(HistoCompare PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#     $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
# )
#
# include(GNUInstallDirs) # Need this to get variables like `CMAKE_INSTALL_INCLUDEDIR`
#
# install(TARGETS HistoCompare
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
# )
#
# install(
#     DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/HistoCompare/
#     FILES_MATCHING PATTERN *.h PATTERN *.hpp
# )
#
# install(
#     PROGRAMS scripts/rootcomp.py scripts/htmlMaker.py
#     TYPE BIN
# )
