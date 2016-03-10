cmake_minimum_required(VERSION 2.8.11)

set(HSPRJ_NAME "DefineProject")
project(${HSPRJ_NAME})

include_directories("include")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#GDAL
find_package(GDAL REQUIRED)
include_directories(${GDAL_INCLUDE_DIR})

#BOOST
Set (Boost_NO_BOOST_CMAKE ON)
find_package(Boost 1.60.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)

qt5_wrap_ui(ui_FILES ui/main.ui)
qt5_add_resources(re_FILES resource/resource.qrc)

set(source_FILES
      source/main.cpp
      include/mainwindow.hpp
      source/mainwindow.cpp
      include/coordinate_system_model.hpp
      source/coordinate_system_model.cpp
      include/coordinate_system_item.hpp
      source/coordinate_system_item.cpp
      include/geographic_coordinate_system_item.hpp
      source/geographic_coordinate_system_item.cpp
      include/projected_coordinate_system_item.hpp
      source/projected_coordinate_system_item.cpp
      include/read_write_file.hpp
      source/read_write_file.cpp
    )

add_executable(DefineProject ${source_FILES} ${ui_FILES} ${re_FILES})

target_link_libraries(DefineProject Qt5::Widgets "${GDAL_LIBRARY}")


