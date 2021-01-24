#define BOOST_TEST_MODULE model_test

#include <iostream>
#include <boost/test/unit_test.hpp>
#include <sstream>
#include "../../model/device/device.h"

typedef luna::core::Device Device;

BOOST_AUTO_TEST_SUITE(model_device_test)

BOOST_AUTO_TEST_CASE(ModelDeviceTest)
{
    Device* dev0 = new Device(0, "device_0");
    Device* dev1 = new Device(1, "device_1");
    Device* dev1_clone = new Device(1, "device_1");

    BOOST_CHECK( dev0->get_hash() != dev1->get_hash() );
    BOOST_CHECK( dev1->get_hash() == dev1_clone->get_hash() );

    BOOST_CHECK( dev0->equal( *dev1 ) == false );
    BOOST_CHECK( dev1->equal( *dev1_clone ) );

    delete( dev0 );
    delete( dev1 );
    delete( dev1_clone );
}

BOOST_AUTO_TEST_CASE(ModelDeviceTestGetters)
{
    int pk = 0;
    const char* name = "device 0";
    const char* tablename = "tablename";

    Device* dev0 = new Device(pk);
    BOOST_TEST_MESSAGE( dev0->as_json() );
    BOOST_CHECK( dev0 && dev0->get_id() == pk );

    Device* dev1 = new Device(name);
    BOOST_CHECK( dev1 && dev1->get_id() == -1 && dev1->get_name() == name );

    Device* dev2 = new Device(tablename, name);
    BOOST_CHECK( dev2 && dev2->get_id() == -1 && dev2->get_name() == name );

    Device* dev3 = new Device(pk, name);
    BOOST_CHECK( dev3 && dev3->get_id() == pk && dev3->get_name() == name );

    Device* dev4 = new Device(pk, tablename, name);
    BOOST_CHECK( dev4 && dev4->get_id() == pk && dev4->get_name() == name );

    delete( dev0 );
    delete( dev1 );
    delete( dev2 );
    delete( dev3 );
    delete( dev4 );
}

BOOST_AUTO_TEST_CASE(ModelDeviceTestJSON)
{
    int ID = 123;
    std::string NAME = "temper_sensor";
    std::string SETTINGS = "{}";
    std::stringstream ss;
    ss << "{\"id\":" << ID << ","
       << "\"name\":" << "\"" << NAME << "\","
       << "\"settings\": " << SETTINGS << "}";

    Device* dev = new Device();
    std::string json = ss.str();
    dev->from_json( json );

    BOOST_CHECK( dev->get_name() == NAME );
    BOOST_CHECK( dev->get_id() == ID );
    delete dev;
}

BOOST_AUTO_TEST_SUITE_END()
