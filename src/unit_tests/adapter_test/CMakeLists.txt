cmake_minimum_required(VERSION 2.6)
project(Test)
find_package(Boost REQUIRED unit_test_framework)

include_directories(../)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(
        AdapterTest
        "adapter_test.cpp"
        "../../database/adapter.cpp"
)

target_link_libraries(
        AdapterTest
        ${Boost_LIBRARIES}
)
                        