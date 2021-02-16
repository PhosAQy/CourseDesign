#pragma once
#include "MySQLUtils.h"
class TeacherService
{
public:
    static void selectAll();
    static void selectById();
    static void addTeacher();
    static void deleteById();
    static void updateAll();
    static void updateItem();

private:
    static MYSQL mysql;
    static MYSQL_RES* result;
    static string id;
    static string name;
    static string gander;
    static string birth;
    static string post;
    static string workYear;
    static string sql;

    static void updateName();
    static void updateGander();
    static void updateBrith();
    static void updatePost();
    static void updateWorkYear();

    static void setId();
    static void setName();
    static void setGander();
    static void setBirth();
    static void setPost();
    static void setWorkYear();

};

