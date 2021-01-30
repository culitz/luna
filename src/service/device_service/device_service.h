#pragma once

#include <algorithm>
#include "../../service/service/service.h"
#include "../../model/device/device.h"
#include "../../database/adapter.h"

namespace luna::core
{

class DeviceService : public Service
{

public:
    DeviceService(db::Adapter& adapter) : Service(adapter) {}
    virtual ~DeviceService() {}

    bool create( IModel& ) override;
    bool read( IModel& ) override;
    bool update( IModel&, IModel& ) override;
    bool delete_item( IModel& ) override;
};

}
