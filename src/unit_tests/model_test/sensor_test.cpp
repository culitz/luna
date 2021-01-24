#include <iostream>
#include <boost/test/unit_test.hpp>
#include "../../model/sensor/sensor.h"

typedef luna::Sensor Sensor;

BOOST_AUTO_TEST_SUITE(model_sensor_test)

BOOST_AUTO_TEST_CASE(ModelSensorTestEqualation)
{
    Sensor* s0 = new Sensor(0, "Sensor_0", 1);
    Sensor* s1 = new Sensor(1, "Sensor_1", 2);
    Sensor* s1_clone = new Sensor(1, "Sensor_1", 2);

    BOOST_CHECK( s0->get_hash() != s1->get_hash() );
    BOOST_CHECK( s1->get_hash() == s1_clone->get_hash() );

    BOOST_CHECK( s0->equal( *s1 ) == false );
    BOOST_CHECK( s1->equal( *s1_clone ) );

    delete( s0 );
    delete( s1 );
    delete( s1_clone );
}

BOOST_AUTO_TEST_CASE(ModelSensorTestGetters)
{
    int pk = 0;
    int fk = 1;
    std::string name = "Sensor_0";

    Sensor* s0 = new Sensor(pk, name, fk);

    BOOST_CHECK( s0->get_id() == pk );
    BOOST_CHECK( s0->get_measurement() == fk );
    BOOST_CHECK( s0->get_name() == name );
    delete( s0 );
}

BOOST_AUTO_TEST_SUITE_END()
