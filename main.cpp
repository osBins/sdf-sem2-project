#include <bits/stdc++.h>
using namespace std;

class teacher;

class csv
{
private:
    vector<vector<string>> data;
    // [
    //     ["name","100","50"],
    //     ["name1","50","100"],
    // ]
    void update(int row, int col)
    {
    }
    void add(int roll)
    {
    }
    void del(int roll)
    {
    }
    void flush()
    {
    }

public:
    csv()
    {
    }
    csv(string file)
    {
    }
    void read()
    {
    }
    friend class teacher;
};

class teacher
{
private:
    string name;
    string password;
public:
    static csv students;
    static csv teachers;
    teacher(string name, string password)
    {
    }
    void add_marks(int roll, string sub_name, int marks)
    {
    }
    void add_student(int roll)
    {
    }
    void del_student(int roll)
    {
    }
};

class parent
{
public:
    parent(int student_roll, string password)
    {
    }
    void print_report()
    {
    }
};

int main()
{
    string greeting = "\tWelcome To lorem ipsum\n\
    1. Enter 1 if you are a teacher\n\
    2. Enter 2 if you are a parent";
    cout << greeting << endl;
    int choice;
    while (true)
    {
        cin >> choice;
        if (choice != 1 || choice != 2)
        {
            cout << "please select from 1 or 2" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    switch (choice)
    {
    case 1:
        //login as teacher
        break;
    case 2:
        //login as parent
        break;
    }
}