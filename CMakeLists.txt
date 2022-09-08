cmake_minimum_required(VERSION 3.16)

project(cpp_worker_starter)

add_subdirectory(slog)

add_executable(sworker)

target_sources(sworker PRIVATE src/main.cpp)
target_include_directories(sworker PRIVATE include)
target_link_libraries(sworker PRIVATE slog)