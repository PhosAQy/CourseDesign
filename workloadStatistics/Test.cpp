//#include <iostream>
//#include <winsock2.h>
//#include <mysql.h>
//#include <string>
//using namespace std;
//MYSQL mysql;
//MYSQL_RES* result;
//MYSQL_FIELD* field;
//MYSQL_ROW row;
//
//int code;
//
//string id;
//string name;
//string gander;
//string birth;
//string post;
//string workYear;
//
//string sql;
//
//unsigned int rowcount;
//unsigned int fieldcount;
//void init();
//void functionService();
//
//void select(int border);
//
//
//class MySQLUtils
//{
//public:
//    static void connect()
//    {
//        mysql_library_init(NULL, 0, 0);
//
//        mysql_init(&mysql);
//
//        if (0 == mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk"))//设置字符集
//        {
//            //cout << "设置字符集成功\n\n" << endl;
//        }
//
//        if (!mysql_real_connect(&mysql, "localhost", "root", "gaoshang", "teacher", 3306, NULL, CLIENT_MULTI_STATEMENTS))//连接数据库
//        {
//            cout << "not connect mysql" << endl;
//        }
//        else
//        {
//            cout << "Successfully connected to MySQL\n\n\n";
//        }
//    }
//
//    static void close()
//    {
//        mysql_free_result(result);
//        mysql_close(&mysql);
//        mysql_server_end();
//        mysql_library_end();
//    }
//};
//
//class TeacherService
//{
//public:
//    static void selectAll()
//    {
//        mysql_query(&mysql, "select *, year(now()) - year(dateOfBirth) as age from teacher_info;");          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//
//    }
//
//    static void selectById()
//    {
//
//        setId();
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        //sql = "select * from student_information where studentId = '10005'";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//
//    }
//
//    static void addTeacher()
//    {
//        setId();
//        setName();
//        setGander();
//        setBirth();
//        setPost();
//        setWorkYear();
//
//        sql = "insert into teacher_info values ('" + id + "', '" + name + "', '" + gander + "', '" + birth + "', '" + post + "', '" + workYear + "');";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        result = mysql_store_result(&mysql);       //获取资源
//        if (!(row = mysql_fetch_row(result)))
//        {
//            cout << "插入数据失败了！" << endl;
//            return;
//        }
//        cout << "成功添加教师！" << endl;
//
//        printData(result);
//    }
//
//    static void deleteById()
//    {
//        setId();
//        sql = "delete from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//        if (row = mysql_fetch_row(result))
//        {
//            cout << "删除失败了！" << endl;
//            return;
//        }
//        cout << "已成功删除！" << endl;
//    }
//
//    static void updateAll()
//    {
//        setId();
//        setName();
//        setGander();
//        setBirth();
//        setPost();
//        setWorkYear();
//        sql = "update teacher_info set name = '" + name + "', gander = '" + gander + "',dateOfBirth = '" + birth + "',post = '" + post + "',workYear = '" + workYear + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//    }
//
//    static void updateItem()
//    {
//        setId();
//
//        cout << "请选择要修改的信息(1，姓名2，性别3，出生日期4，职位5，教龄）：" << endl;
//        select(5);
//        switch (code)
//        {
//        case 1:
//            updateName();
//            break;
//        case 2:
//            updateGander();
//            break;
//        case 3:
//            updateBrith();
//            break;
//        case 4:
//            updatePost();
//            break;
//        case 5:
//            updateWorkYear();
//        default:
//            break;
//        }
//    }
//
//private:
//
//    static void updateName()
//    {
//        setName();
//
//        sql = "update teacher_info set name = '" + name + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        //sql = "select * from student_information where studentId = '10005'";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//        //cout << "修改失败了！" << endl;
//        //cout << "已成功修改！" << endl;
//    }
//
//    static void updateGander()
//    {
//        setGander();
//
//        sql = "update teacher_info set gander = '" + gander + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//        //cout << "修改失败了！" << endl;
//        //cout << "已成功修改！" << endl;
//    }
//
//    static void updateBrith()
//    {
//        setBirth();
//
//        sql = "update teacher_info set dateOfBirth = '" + birth + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        //sql = "select * from student_information where studentId = '10005'";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//        //cout << "修改失败了！" << endl;
//        //cout << "已成功修改！" << endl;
//    }
//
//    static void updatePost()
//    {
//        setPost();
//
//        sql = "update teacher_info set post = '" + post + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        //sql = "select * from student_information where studentId = '10005'";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//        //cout << "修改失败了！" << endl;
//        //cout << "已成功修改！" << endl;
//    }
//
//    static void updateWorkYear()
//    {
//        setWorkYear();
//
//        sql = "update teacher_info set workYear = '" + workYear + "' where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//
//        sql = "select *, year(now()) - year(dateOfBirth) as age from teacher_info where id = '" + id + "';";
//        mysql_query(&mysql, sql.c_str());          //执行SQL语句
//        result = mysql_store_result(&mysql);       //获取资源
//
//        printData(result);
//    }
//    static void setId()
//    {
//        cout << "请输入ID，回车确认！" << endl;
//        cin >> id;
//    }
//
//    static void setName()
//    {
//        cout << "请输入姓名，回车确认！" << endl;
//        cin >> name;
//    }
//
//    static void setGander()
//    {
//        cout << "请输入性别对应序号，回车确认！\n1，男2，女3，其他" << endl;
//        cin >> gander;
//
//    }
//
//    static void setBirth()
//    {
//        cout << "请输入出生日期（例：1990-01-01），回车确认" << endl;
//
//        cin >> birth;
//    }
//
//    static void setPost()
//    {
//        cout << "请输入职位对应序号，回车确认！\n1,讲师2，教授3，干部4，其他" << endl;
//        select(4);
//        switch (code)
//        {
//        case 1:
//            post = "lecturer";
//            break;
//        case 2:
//            post = "professor";
//            break;
//        case 3:
//            post = "cadre";
//            break;
//        case 4:
//            post = "else";
//            break;
//        default:
//            break;
//        }
//
//    }
//    static void setWorkYear()
//    {
//        cout << "请输入教龄，回车确认！" << endl;
//        cin >> workYear;
//    }
//    static void printData(MYSQL_RES* result)
//    {
//        rowcount = mysql_num_rows(result);                //获取记录数
//        fieldcount = mysql_num_fields(result);   //获取字段数
//        while (row = mysql_fetch_row(result))
//        {
//
//            cout << "|";
//            for (unsigned int i = 0; i < fieldcount; i++)
//            {
//                field = mysql_fetch_field_direct(result, i);
//                cout << field->name << ":" << row[i] << "|";
//            }
//            cout << endl;
//        }
//    }
//
//};
//
//
//int main()
//{
//    init();
//
//    return 0;
//}
//
//void init()
//{
//    MySQLUtils::connect();
//    cout << "------------------Welcome to Teacher's Workload Statistics System!------------------" << endl;
//    functionService();
//    MySQLUtils::close();
//}
//
//void functionService()
//{
//    while (1)
//    {
//        cout << "1.Teacher_Management\n2.Workload_Management\n3.Exit" << endl;
//        select(3);
//        switch (code)
//        {
//        case 1:
//            cout << "1.selectAll\n2.selectById\n3.addTeacher\n4.deleteById\n5.updateAll\n6.updateItem\n7.go back" << endl;
//            while (code != 7)
//            {
//                select(7);
//                switch (code)
//                {
//                case 1:
//                    TeacherService::selectAll();
//                    break;
//                case 2:
//                    TeacherService::selectById();
//                    break;
//                case 3:
//                    TeacherService::addTeacher();
//                    break;
//                case 4:
//                    TeacherService::deleteById();
//                    break;
//                case 5:
//                    TeacherService::updateAll();
//                    break;
//                case 6:
//                    TeacherService::updateItem();
//                    break;
//                default:
//                    break;
//                }
//            }
//            break;
//        case 2:
//            cout << "1.selectAllWorkload\n2.selectScoresById\n3.addScores\n4.deleteScoresById\n5.updateAllScores\n6.updatePartSores\n7.go back" << endl;
//            while (code != 7)
//            {
//                select(7);
//                switch (code)
//                {
//                    //case 1:
//                    //    selectAllScores();
//                    //    break;
//                    //case 2:
//                    //    selectScoresById();
//                    //    break;
//                    //case 3:
//                    //    addScores();
//                    //    break;
//                    //case 4:
//                    //    deleteScoresById();
//                    //    break;
//                    //case 5:
//                    //    updateAllScores();
//                    //    break;
//                    //case 6:
//                    //    updatePartSores();
//                    //    break;
//                default:
//                    break;
//                }
//            }
//            break;
//        case 3:
//            cout << "Thanks for Using!\nBye!" << endl;
//            exit(0);
//        default:
//            break;
//        }
//
//    }
//
//}
//
//void select(int border)
//{
//    while (true)
//    {
//        cin >> code;
//        if (code <= border && code > 0)
//        {
//            break;
//        }
//        cout << "请正确输入序号！" << endl;
//    }
//}
