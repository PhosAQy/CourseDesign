#pragma once
#include "MySQLUtils.h"
class WorkloadService
{
public:
    static void selectAll();
    static void selectById();
    static void addWorkloadInfo();
    static void deleteById();
    static void updateAll();
    static void updateItem();

private:
    static MYSQL mysql;
    static MYSQL_RES* result;
    static string id;
    static string course;
    static string Class;
    static string numOfClass;
    static string periods;
    static string sql;

    static void updateCourse();
    static void updateClass();
    static void updateNumOfClass();
    static void updatePeriods();

    static void setId();
    static void setCourse();
    static void setClass();
    static void setNumOfClass();
    static void setPeriods();

};

