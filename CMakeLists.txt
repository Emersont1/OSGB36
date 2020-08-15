project(OSGBpp)
cmake_minimum_required(VERSION 3.2)

include_directories(include)

add_library(osgbpp
src/constants.cpp
src/calculator/angles.cpp
src/calculator/meridian_arc.cpp
src/calculator/transverse_mercator.cpp
src/calculator/geoid_convert.cpp
src/calculator/olson.cpp
src/calculator/grid_ref.cpp
src/calculator/distance.cpp
#src/calculator/zhu.cpp
#src/calculator/ordinance_survey_method.cpp
)

add_executable(test main.cpp)
target_link_libraries(test osgbpp)

add_executable(distance distance_test.cpp)
target_link_libraries(distance osgbpp)