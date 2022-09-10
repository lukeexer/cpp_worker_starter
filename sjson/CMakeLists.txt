cmake_minimum_required(VERSION 3.16)

project(sjson)

find_package(nlohmann_json 3.2.0 REQUIRED)

#add_library(sjson)
add_executable(sjson)

target_sources(sjson PRIVATE src/sjson.cpp)
target_link_libraries(sjson PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(
    sjson
    PRIVATE include)