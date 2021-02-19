#include <iostream>
#include <any>
#include <map>
#include <algorithm>
#include <vector>
#include "model/device/device.h"
#include "service/device_service/device_service_sql_helper.h"

int main()
{
    luna::core::Device dev(12, "first device");
    luna::core::sql::DeviceSqlHelper helper;
    
    std::cout << helper.read(dev) << std::endl;
    std::cout << helper.create(dev) << std::endl;
    return 0;
}