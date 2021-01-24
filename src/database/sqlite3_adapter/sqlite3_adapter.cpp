#include "sqlite3_adapter.h"

namespace luna{
namespace core{
namespace db{

static int callback(void *data, int argc, char **argv, char **szColName)
{
    return 1;
}

AdapterSqlite3::~AdapterSqlite3()
{
    if( database )
        sqlite3_close( database );
}


bool AdapterSqlite3::connect()
{
    rc = sqlite3_open( get_database_name(), &database );
    if( rc != SQLITE_OK )
        return false;
    return true;
}

bool AdapterSqlite3::connect( const char* host, int port, const char* user, const char* pass )
{
    return true;
}

bool AdapterSqlite3::disconnect()
{
    return true;
}

bool AdapterSqlite3::create()
{
    return true;
}

bool AdapterSqlite3::remove()
{
    return true;
}

bool AdapterSqlite3::is_open()
{
    if( rc && rc == SQLITE_OK )
        return true;
    return false;
}

bool AdapterSqlite3::exec_sql( const char* request, tuple_vector* data )
{
    // int exit = 0;
    // exit = sqlite3_open( get_database_name(), &database );
    char** err;
    if( database )
    {
        sqlite3_exec(database, request, nullptr, nullptr, err);
    }
    // sqlite3_close(database);
    return true;
}


}
}
}
