#pragma once
#include "Head.h"
class MySQLUtils
{
private:
    static MYSQL mysql;
    static MYSQL_RES* result;
    static MYSQL_FIELD* field;
    static MYSQL_ROW row;
    static LPSTR url;
    static LPSTR user;
    static LPSTR password;
    static LPSTR database;
public:
    static MYSQL connect();
    static void close(MYSQL mysql, MYSQL_RES* result = nullptr);

};
