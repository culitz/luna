#pragma once

#include <iostream>
#include "../base/imodel.h"

namespace luna 
{

/**
 * Model of simple measurement value record
 */
class Value : public core::IModel
{
private:
    float value;
    string datetime;
    int measurement_id;

public:
    /// Name of table in database
    inline static const string TABLE_NAME = "value";

    /**
     * Default constructor create Model instance.
     */
    Value();

    /**
     * Constructor
     * @param value - value of measurement
     * @param datetime - string datetime serialization 'YYYY-MM-DD'
     * @param measurement_id - FK of entity "measurement"
     */
    Value( float value, string datetime, int measurement_id );

    /**
     * Constructor
     * @param id - PK of entity "value"
     * @param value - value of measurement
     * @param datetime - string datetime serialization 'YYYY-MM-DD'
     * @param measurement_id - FK of entity "measurement"
     */
    Value( int id, float value, string datetime, int measurement_id );

    /// override methods
    size_t get_hash() override;
    string as_json() override;
    ptree as_ptree() override;
    bool from_json( string const& json ) override;
    bool from_ptree( ptree const& ptree ) override;
    ptree& get_ptree() override
    {
        ptree p;
        return p;
    }

    /// getters
    int get_measurement_id() { return measurement_id; }
    float get_value() { return value; }
    string get_datetime(){ return datetime; }

    /// setters
    void set_measurement_id(int measurement_id) { this->measurement_id = measurement_id; }
    void set_value(float value) { this->value = value; }
    void set_datetime(string datetime) { this->datetime = datetime; }
};

}
