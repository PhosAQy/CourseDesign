//#pragma once
//#include <iostream>
//#include <winsock2.h>
//#include <mysql.h>
//#include <string>
//#include <Windows.h>
//using namespace std;
//int main()
//{
//    MYSQL mysql;
//     MYSQL_RES* result;
//     MYSQL_FIELD* field;
//     MYSQL_ROW row;
//     LPSTR url;
//     LPSTR user;
//     LPSTR password;
//     LPSTR database;
//    mysql_library_init(NULL, 0, 0);
//
//    mysql_init(&mysql);
//
//    if (0 == mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"))//设置字符集
//    {
//        //cout << "设置字符集成功\n\n" << endl;
//    }
//
//    if (!mysql_real_connect(&mysql, "localhost", "root", password, database, 3306, NULL, CLIENT_MULTI_STATEMENTS))//连接数据库
//    {
//        cout << "not connect mysql" << endl;
//    }
//    //if (!mysql_real_connect(&mysql, "localhost", "root", "gaoshang", "teacher", 3306, NULL, CLIENT_MULTI_STATEMENTS))//连接数据库
//    //{
//    //    cout << "not connect mysql" << endl;
//    //}
//    else
//    {
//        //cout << "Successfully connected to MySQL\n\n\n";
//    }
//    mysql_query(&mysql, "SET NAMES GBK");
//
//    mysql_query(&mysql, "select *, periods * numOfClass as totalPeriods from workload;");          //执行SQL语句
//    result = mysql_store_result(&mysql);       //获取资源
//
//     unsigned int rowcount = mysql_num_rows(result);                //获取记录数
//     unsigned int fieldcount = mysql_num_fields(result);   //获取字段数
//    while (row = mysql_fetch_row(result))
//    {
//
//        cout << "|";
//        for (unsigned int i = 0; i < fieldcount; i++)
//        {
//            field = mysql_fetch_field_direct(result, i);
//            cout << field->name << ":" << row[i] << "|";
//        }
//        cout << endl;
//    }
//
//    mysql_free_result(result);
//    mysql_close(&mysql);
//    mysql_server_end();
//    mysql_library_end();
// 
//
//    mysql_query(&mysql, "select *, periods * numOfClass as totalPeriods from workload;");          //执行SQL语句
//    result = mysql_store_result(&mysql);       //获取资源
//
//
//}