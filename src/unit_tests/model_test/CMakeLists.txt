cmake_minimum_required(VERSION 2.6)
project(Test)
find_package(Boost REQUIRED unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

if (DEFINED ENV{BOOST_INCLUDE_DIR})
    set(BOOST_INCLUDE_DIR $ENV{BOOST_INCLUDE_DIR})
else ()
    set(BOOST_INCLUDE_DIR "")
endif ()
if (BOOST_INCLUDE_DIR STREQUAL "")
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
elseif (EXISTS ${BOOST_INCLUDE_DIR})
    include_directories(${BOOST_INCLUDE_DIR})
endif ()

add_executable(
        ModelTest
        "device_test.cpp"
        "sensor_test.cpp"
        "../../model/device/device.cpp"
        "../../model/sensor/sensor.cpp"
)

target_link_libraries(
        ModelTest
        ${Boost_LIBRARIES}
)
