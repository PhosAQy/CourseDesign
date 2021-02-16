#include "Head.h"

int Head::code;
MYSQL_FIELD* Head::field;
MYSQL_ROW Head::row;
unsigned int Head::rowcount;
unsigned int Head::fieldcount;

void Head::select(int border)
{
    while (true)
    {
        cin >> code;
        if (code <= border && code > 0)
        {
            break;
        }
        cout << "请正确输入序号！" << endl;
    }
}

void Head::printData(MYSQL_RES* result)
{
    rowcount = mysql_num_rows(result);                //获取记录数
    fieldcount = mysql_num_fields(result);   //获取字段数
    while (row = mysql_fetch_row(result))
    {

        cout << "|";
        for (unsigned int i = 0; i < fieldcount; i++)
        {
            field = mysql_fetch_field_direct(result, i);
            cout << field->name << ":" << row[i] << "|";
        }
        cout << endl;
    }
}