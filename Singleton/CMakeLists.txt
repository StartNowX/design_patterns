project (singleton)

cmake_minimum_required (VERSION 3.5)

add_definitions ("-std=c++11")

include_directories ("./")

# add_library (singleton singleton.cc) target_link_libraries (singleton)

add_executable (test_singleton main.cc singleton.cc)
