#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE base_configurator_test

#include "../../types.h"
#include <iostream>
#include <boost/test/unit_test.hpp>
#include "../../database/sqlite3_adapter/sqlite3_adapter.h"


using namespace luna;

BOOST_AUTO_TEST_SUITE(base_configurator_test)

BOOST_AUTO_TEST_CASE(AdapterWideTest)
{
    string db_name = "test.db";
    core::db::AdapterSqlite3 adapter( db_name.c_str() );

    bool status = adapter.connect();
    if( status )
    {
        string table_name = "contact_list";
        string contact_name = "Stive";
        string contact_lastname = "Smith";

        string create = "CREATE TABLE IF NOT EXIST" + table_name + "(id INTEGER PRIMARY KEY, name TEXT, lastname TEXT);";
        string insert = "INSERT INTO "  + table_name + "(name, lastname) VALUES ( + '" + 
                                                                contact_name + "', '" + contact_lastname + "')";
        string select = "SELECT * FROM " + table_name + ";";

        core::db::tuple_vector query_set;
        bool ok = adapter.exec_sql(create.c_str(), nullptr );
        BOOST_CHECK( ok );

        ok = adapter.exec_sql(insert.c_str(), nullptr);
        BOOST_CHECK( ok );

        ok = adapter.exec_sql(select.c_str(), &query_set );
        if( ok ) 
        {
            size_t count = query_set.size();
            BOOST_CHECK( count > 0 );
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()
