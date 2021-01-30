#include <iostream>
#include <any>
#include <map>
#include <filesystem>
#include <fstream>
#include "types.h"
#include "database/sqlite3_adapter/sqlite3_adapter.h"
#include "database/row/row.h"

typedef luna::core::db::RowVect RowVect;
typedef luna::core::db::Row Row;

static int callback(void *data, int argc, char **argv, char **azColName)
{
    RowVect* vector = (RowVect*) data;
    for(int i = 0; i<argc; i++){
        std::string name = azColName[i];
        std::string value = argv[i];
        std::cout << name << " : "<< value << std::endl;
        Row row;
        row.add<std::string>(name, value);
        vector->push_back(row);
    }
    return 0;
}

int main()
{
    std::string db_name = "/home/ivan/Code/db/AdapterWideTest.db";
    luna::core::db::AdapterSqlite3 adapter( db_name.c_str() );
    adapter.set_callback(&callback);

    bool status = adapter.connect();
    if( status )
    {
        std::string table_name = "contact_list";
        std::string select = "SELECT * FROM " + table_name + ";";

        RowVect* vect = new RowVect();
        bool ok = adapter.exec_sql(select.c_str(), vect );

        for( Row r : *vect )
            std::cout << r.as_json() << std::endl;
        delete vect;
    }
    else
        std::cout << "error" << std::endl;

    return 0;
}
