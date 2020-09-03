cmake_minimum_required(VERSION 2.8.4)
project(luna)

set(TESTING ON)
set(TEST_ROOT src/unit_tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(Boost_USE_MULTITHREADED ON)

find_package(Boost COMPONENTS system REQUIRED)
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
find_package (SQLite3)

if (TESTING)
    add_subdirectory(${TEST_ROOT}/configurator_test)
    add_subdirectory(${TEST_ROOT}/db_configurator_test)
    add_subdirectory(${TEST_ROOT}/adapter_test)
    add_subdirectory(${TEST_ROOT}/sqlite3_adapter_test)

    enable_testing ()
    add_test(NAME ConfiguratorTest COMMAND $<TARGET_FILE:ConfiguratorTest> --log_level=message)
    add_test(NAME DBConfiguratorTest COMMAND $<TARGET_FILE:DBConfiguratorTest> --log_level=message)
    add_test(NAME AdapterTest COMMAND $<TARGET_FILE:AdapterTest> --log_level=message)
    add_test(NAME AdapterSqlite3Test COMMAND $<TARGET_FILE:AdapterTest> --log_level=message)
endif() 

add_executable(
    luna
    src/main.cpp
    src/configurator/configurator.cpp
)

target_link_libraries(
    luna
    ${Boost_LIBRARIES}
    ${SQLite3_LIBRARIES}
)     
