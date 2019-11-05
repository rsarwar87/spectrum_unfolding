cmake_minimum_required(VERSION 3.5)

project(unfolding LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH /opt/Qt/5.12.5/gcc_64)

find_package(Qt5 COMPONENTS Widgets PrintSupport Concurrent REQUIRED)

add_executable(unfolding
  main.cpp
  connection_ann.h
  net.h
  net.cpp
  neuron.cpp
  neuron.h
  simple_psd.h
  simple_psd.cpp
  simple_ann.h
  simple_ann.cpp
  qcustomplot.cpp
  qcustomplot.h
  multiunfold.cpp
  multiunfold.h
  multiunfold.ui
)

target_link_libraries(unfolding PRIVATE Qt5::Widgets)
