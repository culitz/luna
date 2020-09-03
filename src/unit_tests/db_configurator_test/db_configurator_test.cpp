#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE db_configurator_test

#include <boost/test/unit_test.hpp>
#include <iostream>
#include "../../configurator/dbconfig/dbconfig.h"
#include "../tools/file_system.cpp"


static const char* file = "db_config.json";

BOOST_AUTO_TEST_SUITE(db_config_test)
BOOST_AUTO_TEST_CASE(FileCreate)
{
    BOOST_TEST_MESSAGE( "[FileCreate] Creating file" );

    std::string ctx =   "{ \"host\": \"example_db_host\", "
                        "\"db_name\": \"example_db_name\","
                        " \"db_user\": \"example_db_user\", "
                        " \"db_password\": \"example_db_password\", "
                        "\"port\": 5432 }";

    create_file( file, ctx.c_str() );
    
    try{
        luna::DBConfig config( file );  
        bool ok = config.read_file();
        BOOST_CHECK( ok );
        BOOST_TEST_MESSAGE( "Creating file DONE." );
    }catch( std::exception& ex ){
        std::string msg = "[FileCreate] Failed!";
        BOOST_TEST_MESSAGE( msg );
    }
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(db_config_test_params)
BOOST_AUTO_TEST_CASE(ReadFileParams)
{
    BOOST_TEST_MESSAGE( "[ReadFileParams] Creating file" );
    luna::DBConfig config( file );
    
    bool status = false;
    
    try{
        status = config.read_file();
    }catch( ... ){
        BOOST_TEST_MESSAGE("Config parsing failed!");
    }

    if( status )
    {
        if( config.host )
            BOOST_CHECK_EQUAL( config.host.get(), "example_db_host" );
    
        else if( config.port && config.port != -1 )
            BOOST_CHECK_EQUAL( config.port.get(), 5432 );

        else if( config.db_name )
            BOOST_CHECK_EQUAL( config.db_name.get(), "example_db_name" );

        else if( config.db_user )
            BOOST_CHECK_EQUAL( config.db_user.get(), "example_db_user" );

        else if( config.db_password )
            BOOST_CHECK_EQUAL( config.db_password.get(), "example_db_password" );
    
        else
            BOOST_FAIL( "JSON read FAILED!" );
        BOOST_TEST_MESSAGE( "Parsing DONE" );
    }else{
        BOOST_FAIL( "FILE NOT FOUND" );
    }
    delete_file( file );
}

BOOST_AUTO_TEST_SUITE_END()