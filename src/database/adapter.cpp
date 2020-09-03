#include "adapter.h"

namespace luna{
namespace core{
namespace db{

bool Adapter::connect( const char* host, int port, const char* user, const char* pass ){ return true; }

bool Adapter::disconnect(){ return true; }

bool Adapter::create(){ return true; }

bool Adapter::remove(){ return true; }

bool Adapter::exec_sql( const char* request, tuple_vector* data ) { return true; }

}
}
}