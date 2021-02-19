#include "adapter.h"

namespace luna{
namespace core{
namespace db{

bool Adapter::connect( const char* host, int port, const char* user, const char* pass ){ return true; }

bool Adapter::disconnect(){ return true; }

bool Adapter::exec_sql( const char* request, RowVect* data ) { return true; }

bool Adapter::is_open() { return true; }

}
}
}
