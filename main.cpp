#include <bits/stdc++.h>
using namespace std;
class csv
{
private:
    string file;
    void update(int row, int col)
    {
    }
    void add()
    {
    }
    void del(int row)
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
    // friend teacher;
};
class teacher : public csv
{
public:
    teacher(string name, string password)
    {
    }
    void add_marks(string name, string student)
    {
    }
    void add_student(string name)
    {
    }
    void del_student(string name)
    {
    }
};
class parent : public csv
{
public:
    parent(string name, string password)
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