cmake_minimum_required(VERSION 3.16)

# GCC >= 10.2 is required. If it's not your default GCC version, use:
# export CC=/usr/bin/gcc-10
# export CXX=/usr/bin/g++-10
# cmake ..
# cmake --build .

project(sandbox LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(concurrencpp SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/..")
FetchContent_MakeAvailable(concurrencpp)

include(../cmake/coroutineOptions.cmake)

add_executable(sandbox main.cpp)

target_compile_features(sandbox PRIVATE cxx_std_20)

target_link_libraries(sandbox PRIVATE concurrencpp::concurrencpp)

target_coroutine_options(sandbox)
