cmake_minimum_required(VERSION 2.6)
project(Test)

find_package(Boost REQUIRED unit_test_framework)
find_package (SQLite3)

include_directories(../)

include_directories(
        ${Boost_INCLUDE_DIRS}
        ${SQLite3_INCLUDE_DIRS}
)

link_directories(
        ${Boost_LIBRARY_DIRS}
        ${SQLite3_LIBRARIES}
)

add_executable(
        AdapterSqlite3Test
        "sqlite3_adapter_test.cpp"
        "../../database/adapter.cpp"
        "../../database/sqlite3_adapter/sqlite3_adapter.cpp"
)

target_link_libraries(
        AdapterSqlite3Test
        ${Boost_LIBRARIES}
        ${SQLite3_LIBRARIES}
)
                        