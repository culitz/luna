#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <boost/any.hpp>
#include <memory>

#include "../types.h"

namespace luna{
namespace core{
namespace db{


typedef std::map<string, any> tuple;
typedef std::vector<tuple> tuple_vector;
typedef std::shared_ptr<tuple_vector> tuple_vector_sptr;

class Adapter
{
private:
    bool status;
    string database_name;

protected:
    virtual bool connect( const char* host, int port, const char* user, const char* pass );
    virtual bool disconnect();
    virtual bool create();
    virtual bool remove();
    virtual bool exec_sql( const char* request, tuple_vector* data );
    virtual bool is_open();

public:
    Adapter() { status = false; };
    Adapter( const char* database_name ) : database_name( database_name ) {}
    virtual ~Adapter() {};

    const char* get_database_name(){ return database_name.c_str(); }
};

} // db
} // core
} // luna

#endif
