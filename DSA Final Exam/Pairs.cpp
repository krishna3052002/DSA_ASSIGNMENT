#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int n;

    Student(string name, int n)
    {
        this->name = name;
        this->n = n;
    }
};
class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.name != b.name)
        {
            return a.name > b.name;
        }
        return a.n < b.n;
    }
};
int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int n;
        cin >> name >> n;
        Student obj(name, n);
        pq.push(obj);
    }
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().n << " " << endl;

        pq.pop();
    }
    return 0;
}
