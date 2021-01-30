#include "value.h"

namespace luna
{

Value::Value() : IModel( Value::TABLE_NAME.c_str() )
{

}

Value::Value( float value, string datetime, int measurement_id ) : IModel( Value::TABLE_NAME.c_str() )
{
    hash = get_hash();
}

Value::Value( int id, float value, string datetime, int measurement_id ) : IModel( Value::TABLE_NAME.c_str() )
{
    hash = get_hash();
}

size_t Value::get_hash()
{
    hash = IModel::get_hash();
    size_t hash_list[] = {
        std::hash<float>{}( value ),
        std::hash<string>{}( datetime ),
        std::hash<int>{}( measurement_id )
    };
    
    for( size_t h : hash_list )
        hash = hash ^ (h << 1);

    return hash;
}

string Value::as_json()
{
    std::stringstream ss;
    ss  << "{"
        << "\"id\": " << std::to_string( get_id() ) << ", "
        << "\"value\": " << std::to_string( get_value() ) << ", "
        << "\"date\": " << get_datetime() << ", "
        << "\"measurement_id\": " << std::to_string( get_measurement_id() )
        << std::endl;
    return ss.str();
}

ptree Value::as_ptree()
{
    return ptree{};
}

bool Value::from_json(const string &json)
{
    return false;
}

bool Value::from_ptree(const ptree &ptree)
{
    return false;
}

}
