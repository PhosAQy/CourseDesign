#pragma once
#include <iostream>
#include <winsock2.h>
#include <mysql.h>
#include <string>
#include <Windows.h>
using namespace std;

class Head
{
public:
    static int code;
    static MYSQL_FIELD* field;
    static MYSQL_ROW row;
    static unsigned int rowcount;
    static unsigned int fieldcount;


    static void select(int border);
    static void printData(MYSQL_RES* result);
};
