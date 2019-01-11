#include<bits/stdc++.h>

using namespace std;

class Person
{
        string name, dob;
    public:
        Person(){}
        Person(string n, string d)
        {
            name = n;
            dob = d;
        }
        void outPerson()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Date of birth: "<<dob<<endl;
        }
};

class Student : public Person
{
        string ID, Department;
        int rnk = 0;
        map<string, bool> mm;
    public:
        Student(){}
        Student(string n, string d, string id, string dep) : Person(n,d)
        {
            ID = id;
            Department = dep;
        }
        void getStudent(string n, string d, string id, string dep)
        {
            Person(n,d);
            ID = id;
            Department = dep;
        }
        void outStudent()
        {
            outPerson();
            cout<<"ID: "<<ID<<endl;
            cout<<"Department: "<<Department<<endl;
            cout<<"Rank: "<<rnk<<endl;
        }
        int getRank()
        {
            return rnk;
        }
        void setRank(int x, string id)
        {
            if(mm[id]==1)
                cout<<"You have already done rating."<<endl;
            else
                rnk += x;
        }
        string getID()
        {
            return ID;
        }
        bool operator <(Student A)
        {
            return rnk < A.getRank();
        }
};

class Teacher : public Person
{
        string ID, Department;
    public:
        Teacher(){}
        Teacher(string n, string d, string id, string dep) : Person(n,d)
        {
            ID = id;
            Department = dep;
        }
        void getTeacher(string n, string d, string id, string dep)
        {
            Person(n,d);
            ID = id;
            Department = dep;
        }
        string getID()
        {
            return ID;
        }
        void outTeacher()
        {
            outPerson();
            cout<<"ID: "<<ID<<endl;
            cout<<"Department: "<<Department<<endl;
        }
};

int main()
{
    int x;
    vector<Student> stt;
    vector<Teacher> tch;
    while(1)
    {
        cout<<"Enter: 1 to input student, 2 to input teacher, 3 to give rating, 4 to Show information, 5 to show all student list, 6 to show all teacher list, 7 to top 5 list, 0 to exit: ";
        cin>>x;
        if(x==0) break;
        if(x==1)
        {
            string str,str2,str3,str4;
            cout<<"Enter Name: ";
            cin>>(str);
            cout<<"Enter Date of birth: ";
            cin>>(str2);
            cout<<"Enter ID: ";
            cin>>(str3);
            cout<<"Enter Department: ";
            cin>>(str4);
            stt.push_back(Student(str,str2,str3,str4));
        }
        if(x==2)
        {
            string str,str2,str3,str4;
            cout<<"Enter Name: ";
            cin>>(str);
            cout<<"Enter Date of birth: ";
            cin>>(str2);
            cout<<"Enter ID: ";
            cin>>(str3);
            cout<<"Enter Department: ";
            cin>>(str4);
            tch.push_back(Teacher(str,str2,str3,str4));
        }
        if(x==3)
        {
            string str; int p;
            cout<<"Enter your ID: ";
            cin>>str;
            bool check = 0;
            for(int i = 0; i < stt.size(); i++){
                if(stt[i].getID()==str)
                {
                    check = 1;
                    break;
                }
            }
            for(int i = 0; i < tch.size() && check == 0; i++)
            {
                if(tch[i].getID()==str)
                {
                    check = 1;
                    break;
                }
            }
            if(check==0)
                cout<<"Invalid ID"<<endl;
            else
            {
                cout<<"Enter the ID you want to rate: ";
                cin>>str;
                int i;
                bool chk = 0;
                for(i = 0; i < stt.size(); i++)
                {
                    if(stt[i].getID()==str)
                    {
                        chk = 1;
                        break;
                    }
                }
                if(chk==0) cout<<"This ID does not exist."<<endl;
                else
                {
                    cout<<"Enter Rank: ";
                    cin>>p;
                    stt[i].setRank(p,str);
                }
            }
        }
        if(x==4)
        {
            string str;
            cout<<"Enter id to show information: ";
            cin>>str;
            bool check = 0;
            for(int i = 0 ; i < stt.size(); i++)
            {
                if(stt[i].getID()==str)
                {
                    stt[i].outStudent();
                    check = 1;
                }
            }
            for(int i = 0; i < tch.size() && check == 0; i++)
            {
                if(tch[i].getID()==str)
                {
                    tch[i].outTeacher();
                    check = 1;
                    break;
                }
            }
            if(check == 0) cout<<"No information."<<endl;
        }
        if(x==5)
        {
            sort(stt.begin(),stt.end());
            for(int i = 0 ; i < stt.size(); i++)
            {
                stt[i].outStudent();
            }
        }
        if(x==7)
        {
            sort(stt.begin(),stt.end());
            for(int i = 0 ; i < stt.size() && i < 5; i++)
            {
                stt[i].outStudent();
            }
        }
        if(x==5)
        {
            for(int i = 0 ; i < tch.size() && i < 5; i++)
            {
                tch[i].outTeacher();
            }
        }
    }
    return 0;
}
