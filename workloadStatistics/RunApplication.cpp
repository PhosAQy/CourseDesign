#include "RunApplication.h"

void RunApplication::init()
{
    cout << "\n\n\n------------------Welcome to Teacher's Workload Statistics System!------------------" << endl;
    functionService();
}

void RunApplication::functionService()
{
    while (1)
    {
        cout << "1.Teacher_Management\n2.Workload_Management\n3.Exit" << endl;
        Head::select(3);
        switch (Head::code)
        {
        case 1:
            cout << "1.selectAll\n2.selectById\n3.addTeacher\n4.deleteById\n5.updateAll\n6.updateItem\n7.go back" << endl;
            while (Head::code != 7)
            {
                Head::select(7);
                switch (Head::code)
                {
                case 1:
                    TeacherService::selectAll();
                    break;
                case 2:
                    TeacherService::selectById();
                    break;
                case 3:
                    TeacherService::addTeacher();
                    break;
                case 4:
                    TeacherService::deleteById();
                    break;
                case 5:
                    TeacherService::updateAll();
                    break;
                case 6:
                    TeacherService::updateItem();
                    break;
                default:
                    break;
                }
            }
            break;
        case 2:
            cout << "1.selectAll\n2.selectById\n3.addWorkloadInfo\n4.deleteById\n5.updateAll\n6.updateItem\n7.go back" << endl;
            while (Head::code != 7)
            {
                Head::select(7);
                switch (Head::code)
                {
                case 1:
                    WorkloadService::selectAll();
                    break;
                case 2:
                    WorkloadService::selectById();
                    break;
                case 3:
                    WorkloadService::addWorkloadInfo();
                    break;
                case 4:
                    WorkloadService::deleteById();
                    break;
                case 5:
                    WorkloadService::updateAll();
                    break;
                case 6:
                    WorkloadService::updateItem();
                    break;
                default:
                    break;
                }
            }
            break;
        case 3:
            cout << "Thanks for Using!\nBye!" << endl;
            exit(EXIT_SUCCESS);
        default:
            break;
        }

    }
    
}



