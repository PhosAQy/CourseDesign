#include "WorkloadService.h"

MYSQL WorkloadService::mysql;
MYSQL_RES* WorkloadService::result;

string WorkloadService::id;
string WorkloadService::course;
string WorkloadService::Class;
string WorkloadService::numOfClass;
string WorkloadService::periods;

string WorkloadService::sql;

void WorkloadService::selectAll()
{
    try
    {
        mysql = MySQLUtils::connect();

        mysql_query(&mysql, "select *, periods * numOfClass as totalPeriods from workload;");          //执行SQL语句
        result = mysql_store_result(&mysql);       //获取资源

        Head::printData(result);

        MySQLUtils::close(mysql, result);
    }
    catch(exception e)
    {
        cerr << "SQLException!" << endl;
    }
}

void WorkloadService::selectById()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();

        sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
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

void WorkloadService::addWorkloadInfo()
{
    try
    {
        mysql = MySQLUtils::connect();
        setId();
        sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句

        setCourse();
        setClass();
        setNumOfClass();
        setPeriods();
        if (mysql_store_result(&mysql) != NULL)
        {
            sql = "insert into workload values ('" + id + "', '" + course + "', '" + Class + "', '" + numOfClass + "', '" + periods + "');";
            mysql_query(&mysql, sql.c_str());          //执行SQL语句

            sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
            mysql_query(&mysql, sql.c_str());          //执行SQL语句

            result = mysql_store_result(&mysql);       //获取资源

            cout << "成功添加教师！" << endl;

            Head::printData(result);
        }
        else
        {
            cout << "查无此人" << endl;
        }
        MySQLUtils::close(mysql, result);

    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }

}

void WorkloadService::deleteById()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();

        sql = "delete from workload where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句


        sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
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

void WorkloadService::updateAll()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();
        setCourse();
        setClass();
        setNumOfClass();
        setPeriods();

        sql = "update workload set course = '" + course + "', Class = '" + Class + "',numOfClass = '" + numOfClass + "',periods = '" + periods + "' where id = '" + id + "';";
        mysql_query(&mysql, sql.c_str());          //执行SQL语句

        sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
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

void WorkloadService::updateItem()
{
    try
    {
        mysql = MySQLUtils::connect();

        setId();

        cout << "请选择要修改的信息，回车确认！\n\n\n1，课程名称2，班级专业3，班级数量4，课时" << endl;
        Head::select(5);
        switch (Head::code)
        {
        case 1:
            updateCourse();
            break;
        case 2:
            updateClass();
            break;
        case 3:
            updateNumOfClass();
            break;
        case 4:
            updatePeriods();
            break;
        default:
            break;
        }

        MySQLUtils::close(mysql, result);
    }
    catch (exception e)
    {
        cerr << "SQLException!" << endl;
    }
}

void WorkloadService::updateCourse()
{
    setCourse();

    sql = "update workload set course = '" + course + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void WorkloadService::updateClass()
{
    setClass();

    sql = "update workload set Class = '" + Class + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void WorkloadService::updateNumOfClass()
{
    setNumOfClass();

    sql = "update workload set numOfClass = '" + numOfClass + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void WorkloadService::updatePeriods()
{
    setPeriods();

    sql = "update workload set periods = '" + periods + "' where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句

    sql = "select *, periods * numOfClass as totalPeriods from workload where id = '" + id + "';";
    mysql_query(&mysql, sql.c_str());          //执行SQL语句
    result = mysql_store_result(&mysql);       //获取资源

    Head::printData(result);
    //cout << "已成功修改！" << endl;
}

void WorkloadService::setId()
{
    cout << "请输入ID，回车确认！" << endl;
    cin >> id;
}

void WorkloadService::setCourse()
{
    cout << "请输入课程名称，回车确认！" << endl;
    cin >> course;
}

void WorkloadService::setClass()
{
    cout << "请输入班级专业，回车确认！" << endl;
    cin >> Class;

}

void WorkloadService::setNumOfClass()
{
    cout << "请输入班级数量，回车确认！" << endl;
    cin >> numOfClass;
}

void WorkloadService::setPeriods()
{
    cout << "请输入课时，回车确认！" << endl;
    cin >> periods;
}

