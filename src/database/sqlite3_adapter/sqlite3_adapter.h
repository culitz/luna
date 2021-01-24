#ifndef _SQLITE3_ADAPTER_H_
#define _SQLITE3_ADAPTER_H_

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
    char* err_msg;
    int rc;

public:
    AdapterSqlite3() : Adapter() {}
    AdapterSqlite3( const char* database_name ) : Adapter( database_name ) {}
    virtual ~AdapterSqlite3();

    bool connect();
    bool connect( const char* host, int port, const char* user, const char* pass ) override;
    bool disconnect() override;
    bool create() override;
    bool remove() override;
    bool exec_sql( const char* request, tuple_vector* data ) override;
    bool is_open() override;
};

}
}
} // luna

#endif
