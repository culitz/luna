#ifndef _DBCONFIG_H_
#define _DBCONFIG_H_

#include "../../types.h"
#include "../configurator.h"
#include <boost/optional.hpp>

namespace luna{

/**
 * Database configuration json file parser
*/
class DBConfig : core::Config
{
private:
    typedef core::Config Parent;
    
public:
    boost::optional< string > host;
    boost::optional< int > port;
    boost::optional< string > db_user;
    boost::optional< string > db_password;
    boost::optional< string > db_name;

    DBConfig( const char* path ) : core::Config( path ) {} 
    virtual ~DBConfig(){};

    bool read_file() override;
};


}
#endif