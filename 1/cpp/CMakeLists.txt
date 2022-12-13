cmake_minimum_required(VERSION 3.10)
project(AocDayOne)

add_library(ParseData lib/ParseData.cpp lib/ParseData.h)

add_executable(PartOne src/part_one.cpp)
add_executable(PartTwo src/part_two.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(PartOne ParseData)
target_link_libraries(PartTwo ParseData)
