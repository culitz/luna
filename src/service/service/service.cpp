#include "service.h"

namespace luna::core 
{

bool Service::create( IModel& model )
{
    return false;
}

bool Service::read(IModel &)
{
    return false;
}

bool Service::update(IModel &model_old, IModel &model_new)
{
    return false;
}

bool Service::delete_item(IModel &model)
{
    return false;
}

}
