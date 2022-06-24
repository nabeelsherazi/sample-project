cmake_minimum_required(VERSION 3.15)

# Must be before project declaration
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(sample-project VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)

add_executable(sample-project src/main.cpp)
target_compile_features(sample-project PRIVATE cxx_std_17)

target_link_libraries(sample-project
  PRIVATE
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
