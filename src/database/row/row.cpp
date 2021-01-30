#include "row.h"

namespace luna{
namespace core{
namespace db{


Row::Row()
{

}

Row::~Row()
{

}

Row::row_iterator Row::add(string name, any value)
{
    this->insert(std::make_pair(name, value));
    return this->find(name);
}

any Row::get(string name)
{
    auto it = this->find(name);
    return it->second;
}

bool Row::has_field(string name)
{
    auto it = this->find(name);
    if(it == this->end())
        return false;
    return true;
}

string Row::as_json()
{
    std::stringstream ss;
    ss << "{" << std::endl;

    Row::iterator iter = this->begin();
    while(iter != this->end())
    {
       ss << iter->first << ":" << this->get<string>(iter->first, "");
    }

    ss << "}" << std::endl;
    return ss.str();
}

}
}
}
