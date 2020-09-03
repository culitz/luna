cmake_minimum_required(VERSION 2.6)
project(Test)
find_package(Boost REQUIRED unit_test_framework)

# include_directories(inc)
include_directories(../)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(
        ConfiguratorTest
        "configurator_test.cpp"
        "../tools/file_system.cpp"
        "../../configurator/configurator.cpp"
)

target_link_libraries(
        ConfiguratorTest
        ${Boost_LIBRARIES}
)
                        