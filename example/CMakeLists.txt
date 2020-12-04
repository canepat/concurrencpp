cmake_minimum_required(VERSION 3.16)

# GCC >= 10.2 is required. If it's not your default GCC version, use:
# export CC=/usr/bin/gcc-10
# export CXX=/usr/bin/g++-10
# cmake ..
# cmake --build .

project(concurrencppExamples LANGUAGES CXX)

foreach(example IN ITEMS
        async_file_processing
        async_sql
        process_monitor
        synchronous_web_socket)
  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${example}"
          "${CMAKE_CURRENT_BINARY_DIR}/${example}")
endforeach()
