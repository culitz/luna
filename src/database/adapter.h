#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <boost/any.hpp>
#include <memory>

#include "../types.h"
#include "row/row.h"

namespace luna{
namespace core{
namespace db{


class Adapter
{
private:
    bool status;
    string database_name;

protected:
    virtual bool connect( const char* host, int port, const char* user, const char* pass );
    virtual bool disconnect();
    virtual bool exec_sql( const char* request, RowVect* data );
    virtual bool is_open();

public:
    Adapter() { status = false; }
    Adapter( const char* database_name ) : database_name( database_name ) {}
    virtual ~Adapter() {}

    const char* get_database_name(){ return database_name.c_str(); }
};

} // db
} // core
} // luna
