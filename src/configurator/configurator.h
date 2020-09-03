#ifndef _CONFIGURATOR_H_
#define _CONFIGURATOR_H_
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <memory>
#include "../types.h"


namespace luna{
namespace core{

/**
 * Base class for parse json config files
*/
class Config
{
    protected:
        string get_path();
        void set_path( const char* path );

    private:
        string file_path;
        boost::property_tree::ptree config_tree;

    public:
        Config( const char* path ) : file_path(path) {}
        virtual ~Config() = default;
        boost::property_tree::ptree* get_ptree();

        virtual bool read_file();
        
        
        /// Get field value or default value
        template< typename T >
        T get( const char* key, T default_value = T() ) {
            try{
                return config_tree.get< T >( key );
            }catch( ... ){
                return default_value;
            }
        }
};

}
}

#endif