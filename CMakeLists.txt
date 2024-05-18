cmake_minimum_required(VERSION 3.1)
project(grind25)

set(CMAKE_CXX_STANDARD 14)

add_executable(weird cses/weird_algorithm.cpp)
add_executable(dice cses/dice_combinations.cpp)
add_executable(coins cses/minimizing_coins.cpp)