cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE /opt/vcpkg/scripts/buildsystems/vcpkg.cmake)
project(Shoe_bottom VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenCASCADE CONFIG REQUIRED)

include_directories("${OpenCASCADE_INCLUDE_DIR}")

include(CTest)
enable_testing()

add_executable(Shoe_bottom main.cpp)

target_link_libraries(Shoe_bottom ${OpenCASCADE_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
