#include "configurator.h"

namespace luna{
namespace core{


string Config::get_path()
{
    return file_path;
}

void Config::set_path( const char* path )
{
    file_path = path;
}

bool Config::read_file()
{
    try{
        boost::property_tree::read_json(file_path, config_tree);
        return true;
    }catch( std::exception& e ){
        std::cerr << e.what() << std::endl;
        return false;
    }
}

boost::property_tree::ptree* Config::get_ptree()
{
    return &config_tree;
}

}
}