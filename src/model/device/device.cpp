#include "device.h"
#include <boost/property_tree/json_parser.hpp>


namespace luna::core
{

Device::Device() : IModel( TABLE_NAME.c_str() )
{
    hash = get_hash();
}


Device::Device(int64_t id) : IModel(id, TABLE_NAME.c_str() )
{
    hash = get_hash();
}


Device::Device(const char* c_name) : IModel( TABLE_NAME.c_str() )
{
    mName = string(c_name);
    hash = get_hash();
}


Device::Device(const char* table_name, const char *c_name) : IModel( TABLE_NAME.c_str() )
{
    mName = string(c_name);
    hash = get_hash();
}


Device::Device(int64_t id, const char* tablename, string name) :
    IModel( id, tablename )
{
    mName = name;
    hash = get_hash();
}


Device::Device( int64_t id, string name ) : IModel( id, TABLE_NAME.c_str() )
{
    mName = name;
    hash = get_hash();
}


string Device::as_json()
{
    std::stringstream ss;
    ss  << "{" 
        << "\"id\":" << std::to_string( get_id() ) << ","
        << "\"name\":" << mName
        << "}";
    return ss.str();
}


bool Device::from_json( const string& json )
{
    mPtree.clear();
    std::stringstream ss;
    ss << json;
    Parent::from_json(ss, mPtree);
    from_ptree( mPtree );
    mPtree.clear();
    return true;
}


bool Device::from_ptree( const ptree &pt )
{
    mName = pt.get_optional<string>("name");
    mUuid = pt.get_optional<string>("uuid");
    return false;
}


size_t Device::get_hash()
{
    size_t h1 = std::hash<string>{}( get_name() );
    size_t h2 = std::hash<int64_t>{}( get_id() );
    return h1 ^ (h2 << 1);
}


ptree& Device::get_ptree()
{
    return mPtree;
}


string Device::get_name()
{
    if( mName )
        return mName.get();
    return string{};
}


string Device::get_settings()
{
    if( mSettings )
        return mSettings.get();
    else
        return string{};
}

}
