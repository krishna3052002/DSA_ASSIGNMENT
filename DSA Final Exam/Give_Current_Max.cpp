#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
        {
            return true;
        }
        else if (a.marks == b.marks)
        {
             return a.roll > b.roll;  
        } 
        return false;
    }
};
int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            Student s = pq.top();
            cout << s.name << " " << s.roll << " " << s.marks << endl;
        }
        else if (ch == 1)
        {
            if (!pq.empty())
            {
                Student s = pq.top();
                cout << s.name << " " << s.roll << " " << s.marks << endl;
            }
            else
                cout << "Empty" << endl;
        }
        else if (ch == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (pq.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {

                    Student s = pq.top();
                    cout << s.name << " " << s.roll << " " << s.marks << endl;
                }
            }
            else
            {
                cout << "Empty" << endl;
            }
        }
    }
}