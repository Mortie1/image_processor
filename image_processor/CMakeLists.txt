cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
    image_processor.cpp
        lib/parser/parser.cpp
        lib/filters/crop.cpp
        lib/filters/filter.cpp
        lib/BMP/BMP.cpp
        lib/filters/grayscale.cpp
        lib/color/colors.cpp
        lib/filters/negative.cpp
        lib/filters/sharp.cpp
        lib/filters/edge.cpp
        lib/parser/unixpath.cpp
        lib/filters/blur.cpp)
