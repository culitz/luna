/**
* @author im.koryshkin
* ivan.koryshkin@gmail.com
*/
#pragma once
#include <boost/property_tree/json_parser.hpp>
#include "../../types.h"

namespace luna::core
{

/**
 * @class IModel
 * Base database model class 
*/
class IModel
{
private:
    /// Table name in database
    string table_name;

    /// Id in database
    boost::optional<int64_t> id;

protected:
    /// Object unique hash
    int64_t hash;
    IModel( boost::optional<int64_t> id ) : id(id) {}
    IModel( const char* table_name ) : table_name(table_name) { id = -1; }
    IModel( boost::optional<int64_t> id, const char* table_name ) : table_name(table_name), id(id) {}
    ~IModel() {}

public:
    /// Serialize Model to json string
    virtual string as_json() = 0;

    /// Deserialize Model from json string
    virtual bool from_json( string const& json ) = 0;
    virtual bool from_json( std::stringstream& ss, ptree& pt )
    {
        boost::property_tree::read_json(ss, pt);
        id = pt.get_optional<int>("id");
        return true;
    }

    /// Deserialize Model from boost::property_tree::ptree
    virtual bool from_ptree( ptree const& ptree ) = 0;

    /// Get boost::property_tree::ptree
    virtual ptree& get_ptree() = 0;

    /// Get std::map<std::string, std::any>
    virtual std::map<string, any> as_map() = 0;

    /// Get object hash
    virtual size_t get_hash() 
    {
        size_t h1 = std::hash<string>{}( table_name );
        size_t h2 = std::hash<int64_t>{}( get_id() );
        return h1 ^ (h2 << 1);
    }

    /// Get tablename in database
    string get_tablename() { return table_name; }

    /// Get id in database
    int64_t get_id()
    {
        if( id )
            return id.get();
        else
            return -1;
    }

    bool equal( IModel& model ) { return get_hash() == model.get_hash(); }

    template <typename T>
    T extract_value( ptree& pt, string name, T def )
    {
        boost::optional<T> value = pt.get_optional<T>(name);
        if(value)
            return value.get();
        return def;
    }
};



}
