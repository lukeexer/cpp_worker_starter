cmake_minimum_required(VERSION 3.16)

project(slog)

find_package(Boost COMPONENTS REQUIRED program_options log log_setup)

add_library(slog)

target_sources(slog PRIVATE src/slog.cpp)
target_link_libraries(slog PRIVATE ${Boost_LOG_LIBRARY} ${Boost_LOG_SETUP_LIBRARY})
target_include_directories(
    slog
    PUBLIC include)