#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pq.push(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int ch;
        cin>>ch;
        if(ch==0)
        {
          int x;
          cin>>x;
          pq.push(x);
          cout<<pq.top()<<endl;
        }
        else if(ch==1)
        {
            if(!pq.empty())
            cout<<pq.top()<<endl;
            else
            cout<<"Empty"<<endl;
        }
        else if(ch==2)
        {
            if(!pq.empty())
           {
             pq.pop();
            if(pq.empty())
            {
                cout<<"Empty"<<endl;
            }
            else
            {
                cout<<pq.top()<<endl;
            }
           }
           else
           {
            cout<<"Empty"<<endl;
           }
        }

    }
}