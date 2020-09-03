#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE base_configurator_test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../configurator/configurator.h"
#include "../tools/file_system.cpp"


static const char* file = "config.json";


BOOST_AUTO_TEST_SUITE(base_configurator_test)


BOOST_AUTO_TEST_CASE(FileCreate)
{
    std::string ctx = "{ \"id\": 12, \"name\": \"Stiven\", \"lastname\": \"Smith\"}";
    create_file( file, ctx.c_str() );

    luna::core::Config config( file );
    bool ok = config.read_file();
    BOOST_CHECK( ok );
}

BOOST_AUTO_TEST_CASE(ReadFileParams)
{
    luna::core::Config config( file );
    config.read_file();
    try{
        auto tree = config.get_ptree();
        int id = tree->get<int>( "id" );
        std::string name = tree->get< std::string >( "name" );
        std::string lastname = tree->get< std::string >( "lastname" );

        BOOST_CHECK_EQUAL( id, 12 );	
        BOOST_CHECK_EQUAL( name, "Stiven" );
        BOOST_CHECK_EQUAL( lastname, "Smith" );
    }catch( boost::exception& e ){
        BOOST_FAIL( "boost exception while reading JSON" );
    }catch( std::exception& e ){
        BOOST_FAIL( "wide exception while reading JSON" );
    }

    delete_file( file );
}

BOOST_AUTO_TEST_SUITE_END()
