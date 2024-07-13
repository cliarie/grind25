cmake_minimum_required(VERSION 3.6)
project(grind25)

set(CMAKE_CXX_STANDARD 17)

option(LOCAL_TESTING "Enable local testing with freopen" ON)

set(SOURCE_FILE "../cses/building_teams.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILE})

if (LOCAL_TESTING)
    target_compile_definitions(${PROJECT_NAME} PRIVATE LOCAL_TESTING)
endif()
