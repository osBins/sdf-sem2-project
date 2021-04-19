#include <bits/stdc++.h>
using namespace std;

vector<string> student_vector = {"roll", "name", "parent_name", "password", "math", "physics", "chemistry", "computer", "english"};

vector<string> input(string line)
{
    vector<string> result;
    string temp;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] != ',')
        {
            temp += line[i];
        }
        else
        {
            result.push_back(temp);
            temp = "";
        }
    }
    result.push_back(temp);
    return result;
}
string vec_to_string(vector<string> line)
{
    string result;
    for (auto i : line)
    {
        result += i;
        result += ',';
    }
    return result.substr(0, result.size() - 1);
}
template <class T>
int search(vector<T> vec, T element)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == element)
        {
            return i;
        }
    }
    return -1;
}

class teacher;

class csv
{
public:
    vector<vector<string>> data;
    // [
    //     ["name","100","50"],
    //     ["name1","50","100"],
    // ]
    void update(int row, int col)
    {
    }
    void add(string name)
    {
    }
    void del(int roll)
    {
    }
    void flush()
    {
    }
    csv()
    {
    }
    csv(string file)
    {
    }
    string read(int roll)
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
    teacher() {}
    teacher(string nm, string p)
    {
        csv obj1;
        int i, j, c = 0, row;
        for (i = 0; i < obj1.data.size(); i++)
        {
            for (j = 0; j < obj1.data.size(); j++)
            {
                if (obj1.data[i][j] == nm)
                {
                    c = 1;
                    row = i;
                    break;
                }
            }
        }
        if (c == 1)
        {
            for (i = 0; i < obj1.data.size(); i++)
            {
                if (obj1.data[row][i] == p)
                    c = 1;
            }
            if (c == 1)
                cout << "VALID" << endl;
        }
        else
            cout << "NOT VALID" << endl;
    }
    void add_marks(int roll, string sub_name, int marks)
    {
        csv obj;
        int i, j, row, col;
        for (i = 0; i < obj.data.size(); i++)
        {
            for (j = 0; j < obj.data.size(); j++)
            {
                if (stoi(obj.data[i][j]) == roll)
                    row = i;
                if (obj.data[i][j] == sub_name)
                    col = j;
            }
            students.update(row, col);
            obj.data[row][col] = marks;
        }
    }
    void add_student(string name)
    {
        students.add(name);
    }
    void del_student(int roll)
    {
        students.del(roll);
    }
    void print_all_details(){
        
    }
};

class parent
{
public:
    vector<string> data;
    parent(int student_roll, string password)
    {
        vector<string> temp_vec = input(students.read(student_roll));
        if (temp_vec[3] == password)
        {
            data = temp_vec;
        }
        else
        {
            throw 1;
        }
    }
    void print_report()
    {
        cout << vec_to_string(student_vector) << endl;
        cout << vec_to_string(data) << endl;
    }
};
csv students;
csv teachers;
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

    int roll;
    int marks;
    string password;
    string subject_name;
    string name;
    teacher t1;

    switch (choice)
    {
    case 1:
        while (true)
        {
            try
            {
                cout << "please enter your roll number : ";
                cin >> roll;
                cout << "please enter your password : ";
                cin >> password;
                t1 = teacher(roll, password);
            }
            catch (int err)
            {
                if (err == 1)
                {
                    char choice;
                    cout << "wrong password/roll" << endl;
                    cout << "do you want to continue?(y/n): ";
                    cin >> choice;
                    if (choice == 'n')
                    {
                        break;
                    }
                }
            }
        }
        while (true)
        {
            cout << "please select from the following options" << endl
                 << "1. Add marks" << endl
                 << "2. Add new student" << endl
                 << "3. Remove a student" << endl
                 << "4. View all students" << endl
                 << ">>";
            int choice;
            cin >> choice;
            if (choice > 4 || choice < 1)
            {
                cout << "invalid choice, please pick once more" << endl;
            }
            else
            {
                break;
            }
        }

        switch (choice)
        {
        case 1:
            while (true)
            {
                cout << "enter roll number :";
                cin >> roll;
                cout << "enter subject name :";
                cin >> subject_name;
                cout << "enter marks :";
                cin >> marks;
                if (marks > 100 || marks < 0)
                {
                    cout << "marks cannot be less than 0 or greater than 100" << endl;
                    continue;
                }
                else if (search(student_vector, subject_name) == -1)
                {
                    cout << "please enter a valid subject name from the following" << endl;
                    for (int i = 4; i < 9; i++)
                    {
                        cout << student_vector[i];
                    }
                    cout << endl;
                    continue;
                }
                try
                {
                    t1.add_marks(roll, subject_name, marks);
                }
                catch (int a)
                {
                    if (a == 1)
                    {
                        cout << "the roll number you entered does not exists" << endl;
                        continue;
                    }
                }
                cout << "marks were added successfully" << endl;
                break;
            }
            break;
        case 2:
            cout << "enter the name of the student you wish to add : ";
            cin >> name;
            roll = t1.add_student(name);
            cout << "the roll number of the student you entered is : " << roll << endl;
            break;
        case 3:
            
            while(true){
                cout<< "enter the name of the student you wish to delete : ";
                cin>>roll;
                try{
                    t1.del_student(roll);
                }
                catch(int a){
                    if(a == 1){
                        cout<<"the roll number you have entered does not exists"<<endl;
                        continue;
                    }
                }
                break;
            }
            cout<<"student with roll "<<roll<<" was deleted"<<endl;
            break;
        case 4:
            break;
        }
        break;
    case 2:
        //login as parent
        break;
    }
}