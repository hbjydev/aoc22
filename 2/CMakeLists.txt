cmake_minimum_required(VERSION 3.10)
project(AocDayOne)

add_library(RPS lib/RPS.cpp lib/RPS.h)

add_executable(PartOne src/PartOne.cpp)
#add_executable(PartTwo src/part_two.cpp)

include_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(PartOne RPS)
#target_link_libraries(PartTwo ParseData)
