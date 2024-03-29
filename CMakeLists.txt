cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

######################
find_package(Qt4 REQUIRED)
#avoid nameclash boost signals <-> Qt
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

include(${QT_USE_FILE})

#add build dir to see generated uic output
include_directories(${CMAKE_CURRENT_BINARY_DIR})

LINK_DIRECTORIES(${LIBRARY_OUTPUT_PATH})

SET(${CMAKE_LIBRARY_PATH} ${LIBRARY_OUTPUT_PATH})

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/interfaces/comperatorplugin.h src/mainwindow.h src/pluginmanager.h src/interfaces/rosmanager.h src/interfaces/ComperatorPluginFactoryInterface.h src/ressourcetreemodel.h)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})  

file(GLOB PATHCOMPARE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/interfaces/*.cpp)

rosbuild_add_library(rosmanager ${QT_MOC_HPP})
rosbuild_add_executable(pathcompare ${PATHCOMPARE_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})

SET(LIBS_LINK pathcompare ${QT_LIBRARIES})
target_link_libraries(${LIBS_LINK})
