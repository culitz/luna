#include "dbconfig.h"

namespace luna{

bool DBConfig::read_file()
{
    bool status = Parent::read_file();
    if( status )
    {
        host = Parent::get< std::string >( "host" );
        port = Parent::get< int >( "port" );
        db_user = Parent::get< string >( "db_user" );
        db_name = Parent::get< string >( "db_name" );
        db_password = Parent::get< string >( "db_password" );
        return true;
    }

    return false;
}

}