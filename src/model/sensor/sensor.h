#pragma once
#include "../device/device.h"


namespace luna
{

/**
 * Simple sensor model 
 */
class Sensor : public core::Device
{
private:
    typedef core::Device Parent;
    int64_t measurement_id;

public:
    /// Name of table in database
    inline static const string TABLE_NAME = "sensor";

    /**
     * @param id - PK
     * @param name - Sensor name
     * @param measurement_id - FK of entity "Measurement"
     */
    Sensor( int64_t id, string name, int64_t measurement_id );

    /**
     * @param name - Sensor name
     */
    Sensor( string name );
    
    virtual ~Sensor() {}

    /// getters
    int get_measurement() { return measurement_id; }
    
    /// setters
    void set_measurement( int64_t measurement_id ) { this->measurement_id = measurement_id; }

    string as_json() override;
    size_t get_hash() override;
};

}
