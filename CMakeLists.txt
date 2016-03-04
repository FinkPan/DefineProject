cmake_minimum_required(VERSION 2.8.11)

set(HSPRJ_NAME "DefineProject")
project(${HSPRJ_NAME})

include_directories("include")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#GDAL
set(GDAL_INSTALL_PATH "" CACHE PATH "GDAL_PATH")
set(GDAL_LIBS "${GDAL_INSTALL_PATH}/lib/gdal_i.lib")
include_directories("${GDAL_INSTALL_PATH}/include")

#BOOST
set(BOOST_INSTALL_PATH "" CACHE PATH "BOOST_PATH")
include_directories("${BOOST_INSTALL_PATH}/include")

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
      include/coordinate_system_data.hpp
      source/coordinate_system_data.cpp
      include/geographic_coordinate_system.hpp
      source/geographic_coordinate_system.cpp
      include/projected_coordinate_system.hpp
      source/projected_coordinate_system.cpp
      include/coordinate_system_delegate.hpp
      source/coordinate_system_delegate.cpp
      include/read_write_file.hpp
      source/read_write_file.cpp
    )

add_executable(DefineProject ${source_FILES} ${ui_FILES} ${re_FILES})

target_link_libraries(DefineProject Qt5::Widgets "${GDAL_LIBS}")


