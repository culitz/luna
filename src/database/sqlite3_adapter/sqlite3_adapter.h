#pragma once
#include "../adapter.h"
#include <sqlite3.h>

namespace luna{
namespace core{
namespace db{

class AdapterSqlite3 : public Adapter 
{
private:
    typedef Adapter Parent;
    sqlite3* database;
    // char* err_msg;
    int rc;

    bool debug;

public:
    int (*mCallback)(void*,int,char**,char**);

    AdapterSqlite3();
    AdapterSqlite3( const char* database_name );
    virtual ~AdapterSqlite3();

    bool connect();
    bool connect( const char* host, int port, const char* user, const char* pass ) override;
    bool disconnect() override;
    bool exec_sql(const char* request, RowVect* data) override;

    void set_callback(int (*callback)(void*,int,char**,char**)) { mCallback = callback; }

    bool is_open() override;
};

}
}
} // luna
