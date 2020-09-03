#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE base_configurator_test

#include <iostream>
#include <boost/test/unit_test.hpp>
#include "../../database/adapter.h"



BOOST_AUTO_TEST_SUITE(base_configurator_test)

BOOST_AUTO_TEST_CASE(AdapterWideTest)
{
    std::string name = "database_name";
    luna::core::db::Adapter adapter( name.c_str() );
    BOOST_CHECK( std::string(adapter.get_database_name()) == name );
}

BOOST_AUTO_TEST_SUITE_END()
