#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <strstream>
#include <boost/any.hpp>
#include <boost/optional/optional.hpp>
#include "../../types.h"

namespace luna{
namespace core{
namespace db{


class Row : public std::map<string, any>
{
private:
    typedef std::map<string, any>::iterator row_iterator;

public:
    Row();
    virtual ~Row();

    row_iterator add(string name, any value);
    any get(string name);
    bool has_field(string name);

    string as_json();

    template <typename T>
    row_iterator add( string name, T value )
    {
        any any_value = value;
        return add(name, any_value);
    }

    template <typename T>
    T get(string name, T def)
    {
        if(has_field(name))
        {
            any value = this->get(name);
            T t_value = boost::any_cast<T>(value);
            return t_value;
        }
        else
            return def;
    }
};

typedef std::vector<Row> RowVect;
}
}
}
