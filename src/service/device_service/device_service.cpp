#include "device_service.h"

namespace luna::core 
{

bool DeviceService::create( IModel& model )
{
    std::map<string, any> fields = model.as_map();
    int id = std::any_cast<int>( fields["id"] );
    string name = std::any_cast<string>( fields["name"] );
    string uuid = std::any_cast<string>( fields["uuid"] );

    std::stringstream ss;

    return false;
}

bool DeviceService::read( IModel& model )
{
    return false;
}

bool DeviceService::update( IModel& model_old, IModel& model_new )
{
    return false;
}

bool DeviceService::delete_item( IModel& model )
{
    return false;
}

}
