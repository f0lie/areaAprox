cmake_minimum_required(VERSION 2.6)
project (area_approx)

set (area_approx_VERSION_MAJOR 1)
set (area_approx_VERSION_MINOR 0)

configure_file (
    "${PROJECT_SOURCE_DIR}/area_approx_config.h.in"
    "${PROJECT_BINARY_DIR}/area_approx_config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(area_approx main.c)

target_link_libraries(area_approx m)