#pragma once
#include <sstream>
#include "../base/imodel.h"

namespace luna::core 
{

/**
 * @class Device
 * Model object for Device
 */
class Device : public IModel
{
private:
    typedef IModel Parent;
    inline static const string TABLE_NAME = "device";
    boost::optional<string> mName;
    boost::optional<string> mUuid;
    boost::optional<string> mSettings;
    ptree mPtree;

public: 
    Device();
    Device( int64_t id );
    Device( const char* name );
    Device( const char* table_name, const char* name );
    Device( int64_t id, const char* tablename, string name );
    Device( int64_t id, string name );

    virtual ~Device() {}

    /// Serialization to json string
    string as_json() override;

    /// Deserialize Model from json string
    bool from_json( string const& json ) override;

    /// Deserialize Model from boost::property_tree::ptree
    bool from_ptree( ptree const& ptree ) override;

    size_t get_hash() override;
    ptree& get_ptree() override;

    std::map<string, any> as_map() override;

    string get_name();
    string get_uuid();
    string get_settings();
};

}
