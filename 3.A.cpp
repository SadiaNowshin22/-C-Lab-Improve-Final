#include<bits/stdc++.h>

using namespace std;

class Person
{
    string name, birth;
    public:
        Person(){}
        Person(string name,string birth )
        {
            this->name = name;
            this->birth = birth;
        }
        void viewPerson()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Birthday: "<<this->birth<<endl;
        }
};

class Department
{
    string dept;
public:
    Department(){}
    Department(string dept)
    {
        this->dept = dept;
    }
    void view_Department()
    {
        cout<<"Department Name: "<<this->dept<<endl;
    }
};

class Student : public Person
{
    int id;
    Department department;
public:
    Student(){}
    Student(string name,string birth,int id,Department dept) : Person(name,birth)
    {this->id = id;
    department = dept;}
    void viewStudent()
    {
        viewPerson();
        department.view_Department();
        cout<<"ID : "<<this->id<<endl;
    }
};

class Teacher : public Person
{
    int T_id;
    Department department;
public:
    Teacher(){}
    Teacher(string name,string birth, int T_id,Department dept) : Person(name,birth)
    {
        this->T_id = T_id;
        department = dept;
    }
};

class Society_mem : public Student
{
    string title;
public:
    Society_mem(){}
    Society_mem(string name,string birth,int id,Department department,string title) : Student(name,birth,id,department)
    {
        this->title = title;
    }
    void view_memberInfo()
    {
        cout<<"Society Member Info: "<<endl;
        viewStudent();
        cout<<"Title : "<<this->title<<endl;
    }
};
int main()
{
    Department department("CSE");

    Teacher *teachers[3] =
    {
        new Teacher("Kamal Hossain Chowdhury","01-02-1980",1,department),
        new Teacher("Khairun Nahar","17-05-1989",2,department),
        new Teacher("Faisal Bin Abdul Aziz","20-12-1981",3,department)
    };
    Student *students[3] =
    {
        new Student("Sadia Nowshin","02-02-1996",11708011,department),
        new Student("Shanta Roy","03-05-1997",11708012,department),
        new Student("Chaity Saha","30-12-1997",11708013,department)
    };
    Society_mem *members[3]=
    {
        new Society_mem("Jawad Shafi","11-02-1998",1150804,department,"Member"),
        new Society_mem("Shaheen Nizam","17-11-1996",11508010,department,"GS"),
        new Society_mem("Sejan","22-09-1998",11508010,department,"Member")
    };
    int teach_Scores[3][2]={(2,3),(3,3),(2,4)};
    int stu_Marks[3][2]={(2,2),(3,2),(3,3)};
    int finalScore[2];
    for(int i=0;i<2;i++)
    {
        int result=0;
        for(int j=0;j<3;j++)
        {
           result+=teach_Scores[j][i]+stu_Marks[j][i];
        }
        finalScore[i]=result;
    }
    cout<<"DISPLAY"<<endl;
    for(int i=0;i<2;i++)
    {
        members[i]->viewStudent();
    }
}
