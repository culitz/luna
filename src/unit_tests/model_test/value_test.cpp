#include <iostream>
#include <boost/test/unit_test.hpp>
#include "../../model/value/value.h"

typedef luna::Value Value;

BOOST_AUTO_TEST_SUITE(model_value_test)

BOOST_AUTO_TEST_CASE(ModelValueTestEqualation)
{
    Value* v0 = new Value(0.0, "2020-02-01", 1);
    Value* v1 = new Value(1.0, "2020-01-01", 2);
    Value* v1_clone = new Value(1.0, "2020-01-01", 2);

    BOOST_CHECK( v0->get_hash() != v1->get_hash() );
    BOOST_CHECK( v1->get_hash() == v1_clone->get_hash() );

    BOOST_CHECK( v0->equal( *v1 ) == false );
    BOOST_CHECK( v1->equal( *v1_clone ) );

    delete( v0 );
    delete( v1 );
    delete( v1_clone );
}

BOOST_AUTO_TEST_SUITE_END()
