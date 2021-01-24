#include "sensor.h"

namespace luna
{

Sensor::Sensor( int64_t id, string name, int64_t measurement_id ): 
        Device( id, TABLE_NAME.c_str(), name.c_str() ), measurement_id(measurement_id) 
{
    hash = get_hash();
}


Sensor::Sensor( string name ) : Device( name.c_str() )
{
    hash = get_hash();
}


string Sensor::as_json()
{
    std::stringstream ss;
    ss << "{";
    ss << "\"id\": " << std::to_string( Parent::get_id() ) << std::endl;
    ss << "\"name\": " << Parent::get_name() << std::endl;
    ss << "\"value_type\"" << std::to_string( measurement_id ) << std::endl;
    ss << "}";
    return ss.str();
}

size_t Sensor::get_hash()
{
    size_t h1 = Parent::get_hash();
    size_t h2 = std::hash<int>{}(measurement_id);
    return h1 ^ (h2 << 1);
}

}
