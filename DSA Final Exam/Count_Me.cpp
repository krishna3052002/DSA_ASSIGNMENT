#include <bits/stdc++.h>
using namespace std;
class Word
{
public:
    string w;
    int val;
    Word(string w, int val)
    {
        this->w = w;
        this->val = val;
    }
};
class cmp
{
public:
    bool operator()(Word a, Word b)
    {
        return a.val < b.val;
    }
};
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string sentence;
        getline(cin, sentence);
        string word;
        stringstream ss(sentence);
        map<string, int> mp;
        while (ss >> word)
        {

            mp[word]++;
        }
        priority_queue<Word, vector<Word>, cmp> pq;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->first, it->second});
        }
        
        Word ans = pq.top();
        // while(!pq.empty())
        // {
        //     Word x=pq.top();
        //   if(x.val==ans.val)
        //   {
        //     ans=x;
        //     pq.pop();
        //   }
        //   else{
        //     break;
        //   }
          
        // }
        string w;
        map<string, int> mp2;
        stringstream ss2(sentence);
         while (ss2 >> w)
        {

          mp2[w]++;
           int x=mp2[w];
           if(x==ans.val)
           {
            break;
           }
        }
        for (auto it = mp2.begin(); it != mp2.end(); it++)
        {
            
          if(it->second==ans.val)
          {
             cout<<it->first<<" "<<it->second<<endl;
             break;
          }
        }
        
       
    }
    return 0;
}