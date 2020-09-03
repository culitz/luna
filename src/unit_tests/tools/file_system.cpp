#include <iostream>
#include <fstream>
#include <cstdio>


static bool create_file( const char* filename, const char* content )
{
    std::ofstream fout( filename );
    if( fout.is_open() )
    {
        fout << content;
        fout.close();
        return true;
    }

    return false;
}

static void delete_file( const char* filename )
{
    std::remove( filename );
}