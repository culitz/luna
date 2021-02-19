#pragma once

#include <strstream>
#include <algorithm>
#include <initializer_list>
#include "../../types.h"
#include "../../model/base/imodel.h"

namespace luna::core::sql
{

class DeviceSqlHelper
{
public:
    DeviceSqlHelper() = default;
    virtual ~DeviceSqlHelper() = default;

    string create( IModel& model );
    string read( IModel& model );
    string update( IModel& model_old, IModel& model_new );
    string delete_item( IModel& model );
    string build_filter( IModel& model );

    std::map<string, string> unpack( IModel& model );
};

}
