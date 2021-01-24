#pragma once

#include <iostream>
#include <memory>
#include <any>
#include "../../model/base/imodel.h"
#include "../../database/adapter.h"


namespace luna::core 
{


class Service
{
public:
    Service( db::Adapter& ) {}
    virtual ~Service() {}

    virtual bool create( IModel& );

    virtual bool read( IModel& );

    virtual bool update( IModel& model_old, IModel& model_new );
    
    virtual bool delete_item( IModel& model );

private:
    
};

}
