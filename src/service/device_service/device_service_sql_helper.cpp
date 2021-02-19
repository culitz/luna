#include "device_service_sql_helper.h"

namespace luna::core::sql
{

string DeviceSqlHelper::create( IModel& model )
{
    auto m = unpack(model);
    string id = m["id"];
    string name = m["name"];
    string uuid = m["uuid"];

    std::stringstream ss;
    ss  << "INSERT INTO " << model.get_tablename() 
        << "(id, name, uuid) VALUES (" 
        << id << ", "
        << name << ", "
        << uuid << ")";

    return ss.str(); 
}

string DeviceSqlHelper::read( IModel& model )
{
    string filter = build_filter(model);
    std::stringstream ss;
    ss  << "SELECT * FROM " << model.get_tablename() << " " << filter;
    return ss.str();
}

string DeviceSqlHelper::update( IModel& model_old, IModel& model_new )
{

}

string DeviceSqlHelper::delete_item( IModel& model )
{

}

std::map<string, string> unpack( IModel& model )
{
    std::map<string, string> m;
    for( std::pair<string, any> p: model.as_map() )
    {
        string key = p.first;
        any v = p.second;
        string value = boost::any_cast<string>(v);
        m.insert( std::make_pair(key, value) );
    }

    return m;
}

string DeviceSqlHelper::build_filter( IModel& model )
{
    auto m = unpack(model);
    std::vector<string> v;

    for( std::pair<string, string> item: m )
    {
        if(item.second != "" && item.second != "-1")
        { 
            v.push_back(item.first + "=" + item.second);
            v.push_back("AND");
        } 
    }
    v.erase(v.end()-1);

    std::stringstream ss;
    std::for_each(v.begin(), v.end(), [&ss]( string& s ){ ss << s << " "; });
    return ss.str();
}

}