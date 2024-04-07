#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        list<int> l;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            l.push_back(x);
        }
        set<int> s;
        for (auto it = l.begin(); it != l.end(); it++)
        {
            s.insert(*it);
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
    return 0;
}
