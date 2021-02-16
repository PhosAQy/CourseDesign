#include "TeacherService.h"

MYSQL TeacherService::mysql;
MYSQL_RES* TeacherService::result;

string TeacherService::id;
string TeacherService::name;
string TeacherService::gander;
string TeacherService::birth;
string TeacherService::post;
string TeacherService::workYear;

string TeacherService::sql;

void TeacherService::selectAll()
{
    try
    {
        mysql = MySQLUtils::connect();

        mysql_query(&mysql, "select *, year(now()) - year(dateOfBirth) as age from teacher_info;");          //执行SQL语句
        result = mysql_store_result(&mysql);       //获取资源

        Head::printData(result);

        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
    
}

void TeacherService::selectById()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();

        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
        //sql = "select * from teacher_info where id = '10001'";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句
        result = mysql_store_result(&mysql);       //获取资源

        Head::printData(result);
        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
    
}

void TeacherService::addTeacher()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();
        setName();
        setGander();
        setBirth();
        setPost();
        setWorkYear();

        sql = "insert into teacher_info values ('" + id + "', '" + name + "', '" + gander + "', '" + birth + "', '" + post + "', '" + workYear + "');";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句

        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句

        result = mysql_store_result(&mysql);       //获取资源

        cout << "成功添加教师！" << endl;

        Head::printData(result);
        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
    
}

void TeacherService::deleteById()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();

        sql = "delete from teacher_info where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句


        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句
        result = mysql_store_result(&mysql);       //获取资源
        cout << "已成功删除！" << endl;
        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
    
}

void TeacherService::updateAll()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();
        setName();
        setGander();
        setBirth();
        setPost();
        setWorkYear();

        sql = "update teacher_info set name = '" + name + "', gander = '" + gander + "',dateOfBirth = '" + birth + "',post = '" + post + "',workYear = '" + workYear + "' where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句

        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());
        result = mysql_store_result(&mysql);       //获取资源

        Head::printData(result);
        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
    
}

void TeacherService::updateItem()
{
    mysql = MySQLUtils::connect();

    setId();

    cout << "请选择要修改的信息(1，姓名2，性别3，出生日期4，职位5，教龄）：" << endl;
    Head::select(5);
    switch (Head::code)
    {
    case 1:
        updateName();
        break;
    case 2:
        updateGander();
        break;
    case 3:
        updateBrith();
        break;
    case 4:
        updatePost();
        break;
    case 5:
        updateWorkYear();
    default:
        break;
    }

    MySQLUtils::close(mysql, result);
}

void TeacherService::updateName()
{
    setName();

    sql = "update teacher_info set name = '" + name + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void TeacherService::updateGander()
{
    setGander();

    sql = "update teacher_info set gander = '" + gander + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void TeacherService::updateBrith()
{
    setBirth();

    sql = "update teacher_info set dateOfBirth = '" + birth + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void TeacherService::updatePost()
{
    setPost();

    sql = "update teacher_info set post = '" + post + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void TeacherService::updateWorkYear()
{
    setWorkYear();

    sql = "update teacher_info set workYear = '" + workYear + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void TeacherService::setId()
{
    cout << "请输入ID，回车确认！" << endl;
    cin >> id;
}

void TeacherService::setName()
{
    cout << "请输入姓名，回车确认！" << endl;
    cin >> name;
}

void TeacherService::setGander()
{
    cout << "请输入性别对应序号，回车确认！\n1，男2，女3，其他" << endl;
    Head::select(3);
    switch (Head::code)
    {
    case 1:
        gander = "man";
        break;
    case 2:
        gander = "woman";
        break;
    case 3:
        gander = "else";
    default:
        break;
    }

}

void TeacherService::setBirth()
{
    cout << "请输入出生日期（例：1990-01-01），回车确认" << endl;
    cin >> birth;
}

void TeacherService::setPost()
{
    cout << "请输入职位对应序号，回车确认！\n1,讲师2，教授3，干部4，其他" << endl;
    Head::select(4);
    switch (Head::code)
    {
    case 1:
        post = "lecturer";
        break;
    case 2:
        post = "professor";
        break;
    case 3:
        post = "cadre";
        break;
    case 4:
        post = "else";
        break;
    default:
        break;
    }
}

void TeacherService::setWorkYear()
{
    cout << "请输入教龄，回车确认！" << endl;
    cin >> workYear;
}
