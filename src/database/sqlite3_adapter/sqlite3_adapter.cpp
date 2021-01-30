#include "sqlite3_adapter.h"

namespace luna{
namespace core{
namespace db{


AdapterSqlite3::AdapterSqlite3() : Adapter()
{

}

AdapterSqlite3::AdapterSqlite3(const char *database_name) : Adapter( database_name )
{
    debug = true;
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


bool AdapterSqlite3::is_open()
{
    if( rc == SQLITE_OK )
        return true;
    return false;
}

bool AdapterSqlite3::exec_sql(const char* request, RowVect* data)
{
    rc = sqlite3_open(get_database_name(), &database);

    if(is_open())
    {
        sqlite3_exec(database, request, mCallback, (void*) data, nullptr);
        return true;
    }

    if(database)
        sqlite3_close(database);

    return false;
}


}
}
}
