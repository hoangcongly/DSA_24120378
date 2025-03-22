#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int tim(string s, char k)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==k)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int n;
   map<string,vector<string>>mp;
   for(int i=0; i<n; i++)
   {
    string s;
    getline(cin, s);
    int pos= tim(s,'-');
    string t1= s.substr(0,pos-1);
    string t2= s.substr(pos+1);
    mp[t1].push_back(t2);
    mp[t2].push_back(t1);
   }
   for(auto it:mp)
   {
    vector<string> tmp=it.second;
    sort(tmp.begin(),tmp.end());
    cout << it.first << ": ";
    for(int i=0; i<tmp.size(); i++)
    {
        cout << tmp[i];
    }
   }
}