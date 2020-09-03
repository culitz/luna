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
    int rc = sqlite3_open( get_database_name(), &database );
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

bool AdapterSqlite3::exec_sql( const char* request, tuple_vector* data )
{
    int exit = 0; 
    exit = sqlite3_open("abba.db", &database); 
  
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(database) << std::endl; 
        return false; 
    } 
    sqlite3_close(database); 
    return true;
}


}
}
}