#include "MySQLUtils.h"

MYSQL MySQLUtils::mysql;
MYSQL_RES* MySQLUtils::result;
MYSQL_FIELD* MySQLUtils::field;
MYSQL_ROW MySQLUtils::row;
LPTSTR MySQLUtils::url = new char[MAX_PATH];
LPTSTR MySQLUtils::user = new char[MAX_PATH];
LPTSTR MySQLUtils::password = new char[MAX_PATH];
LPTSTR MySQLUtils::database = new char[MAX_PATH];
MYSQL MySQLUtils::connect()
{
    mysql_library_init(NULL, 0, 0);

    mysql_init(&mysql);

    if (0 == mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"))//设置字符集
    {
        //cout << "设置字符集成功\n\n" << endl;
    }
    GetPrivateProfileString("MySQL", "url", NULL, url, 20, "..//workloadStatistics//config.ini");
    GetPrivateProfileString("MySQL", "user", NULL, user, 20, "..//workloadStatistics//config.ini");
    GetPrivateProfileString("MySQL", "password", NULL, password, 20, "..//workloadStatistics//config.ini");
    GetPrivateProfileString("MySQL", "database", NULL, database, 20, "..//workloadStatistics//config.ini");
    
    if (!mysql_real_connect(&mysql, url, user, password, database, 3306, NULL, CLIENT_MULTI_STATEMENTS))//连接数据库
    {
        cout << "not connect mysql" << endl;
    } 
    //if (!mysql_real_connect(&mysql, "localhost", "root", "gaoshang", "teacher", 3306, NULL, CLIENT_MULTI_STATEMENTS))//连接数据库
    //{
    //    cout << "not connect mysql" << endl;
    //}
    else
    {
        //cout << "Successfully connected to MySQL\n\n\n";
    }
    mysql_query(&mysql, "SET NAMES GBK");
    return mysql;
}

void MySQLUtils::close(MYSQL mysql, MYSQL_RES* result)
{
    mysql_free_result(result);
    mysql_close(&mysql);
    mysql_server_end();
    mysql_library_end();
}