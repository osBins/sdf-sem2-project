#include <bits/stdc++.h>
using namespace std;

vector<string> student_vector = {"Roll No.", "Name", "Password", "Mathematics", "Physics", "Chemistry", "Computers", "English"};

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
    string filename;
    void update(int row, int col, int marks)
    {
        data[row][col] = to_string(marks);
    }
    int add(string name)
    {
        string str;
        int roll = stoi(data[data.size() - 1][0]) + 1;
        str += to_string(roll);
        str += "," + name;
        string pass;
        cout << "\tAssign Password to Student : ";
        fflush(stdin);
        cin >> pass;
        str += "," + pass + ",,,,,";
        data.push_back(input(str));
        return roll;
    }
    void flush()
    {
        ofstream data1(filename);
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data[i].size(); j++)
            {
                data1 << data[i][j];
                if (j != data[i].size() - 1)
                {
                    data1 << ",";
                }
            }
            if (i != data.size() - 1)
                data1 << endl;
        }
    }
    csv()
    {
    }
    csv(string file)
    {
        ifstream data1(file);
        filename = file;
        while (data1.eof() != 1)
        {
            string o;
            getline(data1, o);
            data.push_back(input(o));
        }
    }
    ~csv()
    {
        flush();
    }
    string read(int roll)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i][0] == to_string(roll))
            {
                string str;
                str += data[i][0] + "," + data[i][1];
                for (int j = 3; j < 8; j++)
                {
                    str += data[i][j] + ",";
                }
                str.pop_back();
                return str;
            }
        }
        return string();
    }
};

class teacher
{
private:
    string name;
    int rollNum;
    string password;

public:

    teacher() {};
    teacher(int nm, string p, csv &obj1)
    {
        int i, j, c = 0, row;
        for (i = 0; i < obj1.data.size(); i++)
        {
            if (obj1.data[i][0] == to_string(nm) && obj1.data[i][2] == p)
            {
                return;
            }
        }
        throw 1;
    }
    void add_marks(int roll, string sub_name, int marks, csv students)
    {
        int i, j, row, col;
        for (i = 0; i < students.data.size(); i++)
        {
            if (students.data[i][0] == to_string(roll))
            {
                for (int j = 0; j < student_vector.size(); j++)
                {
                    if (student_vector[j] == sub_name)
                    {
                        row = i;
                        col = j;
                        students.update(row, col, marks);
                        return;
                    }
                }
            }
        }
        throw 1;
    }
    int add_student(string name, csv &students)
    {
        return students.add(name);
    }
    void print_all_details()
    {
         int i = 0;
        cout << endl;
        vector<string>data1;
        ifstream s_file;
    string line,word;
   s_file.open("students.csv");
     while(!s_file.eof()){
         getline(s_file, line);
        stringstream sent(line);
          while (getline(sent, word,',')) {
            data1.push_back(word);
        }
            cout << "|";
            int i;
        for (i = 0; i<data1.size(); i++)
        {
            if (i != 2)
            {
                printf("%17s|",data1[i].data());
            }
        }
        data1.clear();
        cout << endl;
    }
    }
};

class parent
{
public:
    vector<string> data;
    parent() {}
    parent(int student_roll, string password, csv &students)
    {
        for (int i = 0; i < students.data.size(); i++)
        {
            if (students.data[i][0] == to_string(student_roll) && students.data[i][2] == password)
            {
                data = students.data[i];
                return;
            }
        }
        throw 1;
    }
    void print_report()
    {
        int i = 0;
        cout << "|";
        for (; i < student_vector.size(); i++)
        {
            if (i != 2)
                printf("%17s|", student_vector[i].data());
        }
        cout << endl;
        cout << "|";
        for (i = 0; i < data.size(); i++)
        {
            if (i != 2)
            {
                printf("%17s|", data[i].data());
            }
        }
        cout << endl;
    }

};
csv students("students.csv");
csv teachers("teachers.csv");
int main()
{
    string greeting = "\n\n\tWelcome To Student Report Card Management System\n\
    \t\t1. Enter 1 if you are a teacher\n\
    \t\t2. Enter 2 if you are a parent";
    cout << greeting << endl;
    int choice;
    while (true)
    {
        cout << "\t\t>> ";
        cin >> choice;
        if (choice == 1 || choice == 2)
        {
            break;
        }
        else
        {
            cout << "\tInvalid option. Please try again." << endl;
            continue;
        }
    }

    int roll;
    int marks;
    string password;
    string subject_name;
    string name;
    teacher t1;
    parent p1;

    switch (choice)
    {
    case 1:
        while (true)
        {
            try
            {
                cout << "\tEnter your Employee ID : ";
                cin >> roll;
                cout << "\tEnter your Password : ";
                cin >> password;
                cout << "\n";
                t1 = teacher(roll, password, teachers);
            }
            catch (int err)
            {
                if (err == 1)
                {
                    char choice;
                    cout << "\tError. Incorrect details." << endl;
                    cout << "\tDo you want to try again?(y/n): ";
                    cin >> choice;
                    if (choice == 'n')
                    {
                        break;
                    }
                    else{
                        continue;
                    }
                }
            }
            break;
        }
        while (true)
        {
            cout << "\tSelect from the Following Options - " << endl
                 << "\t\t1. Add marks" << endl
                 << "\t\t2. Add new student" << endl
                 << "\t\t3. View all students" << endl
                 << "\t\t>> ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                while (true)
                {
                    cout << "\tEnter Roll Number :";
                    cin >> roll;
                    cout << "\tEnter Subject Name :";
                    cin >> subject_name;
                    cout << "\tEnter Marks :";
                    cin >> marks;
                    cout << endl;
                    if (marks > 100 || marks < 0)
                    {
                        cout << "\tInvalid Value of Marks entered." << endl;
                        continue;
                    }
                    else if (search(student_vector, subject_name) == -1)
                    {
                        cout << "\tInvalid Subject Name entered." << endl;
                        for (int i = 4; i < 9; i++)
                        {
                            cout << student_vector[i] << " ";
                        }
                        cout << endl;
                        continue;
                    }
                    try
                    {
                        t1.add_marks(roll, subject_name, marks, students);
                    }
                    catch (int a)
                    {
                        if (a == 1)
                        {
                            cout << "\tThe roll number you have entered does not exist." << endl;
                            continue;
                        }
                    }
                    cout << "\n\tMarks were succesfully updated." << endl;
                    break;
                }
                break;
            case 2:
                cout << "\tEnter Name of New Student : ";
                cin.ignore(100,'\n');
                getline(cin, name);
                roll = t1.add_student(name, students);
                cout << "\tAssigned Roll Number is : " << roll << endl;
                break;
            case 3:
                t1.print_all_details();
                break;
            default:
                continue;
                break;
            }
            break;
        }

        break;
    case 2:
        //login as parent
        while (true)
        {
            try
            {
                cout << "\t\tEnter your Ward's Roll Number : ";
                cin >> roll;
                cout << "\t\tEnter your Password : ";
                cin >> password;
                p1 = parent(roll, password, students);
            }
            catch (int a)
            {
                if (a == 1)
                {
                    cout << "\n\tInvalid Credentials. Try again.\n" << endl;
                    continue;
                }
            }
            break;
        }
        cout << "\t\t\tHere is the report of your ward" << endl;
        p1.print_report();
        cout << endl;
        break;
    }
}
