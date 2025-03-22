// Set.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

bool Kiem_tra_set(int* a, int n, int m)
{
    set<int> s;
    for (int i=0; i<n; i++)
    {
        s.insert(a[i]);
    }
    return s.find(m) != s.end();
}
bool Kiem_tra_map(int* a, int n, int m)
{
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = 1;
    }
    return mp.find(m) != mp.end();
}
int found_max_appear(int* a, int n)
{
    map<int, int> mp;
    for (int i=0; i<n; i++)
    {
        mp[a[i]]++;
    }
    int max_count = 0;
    int val = -1;
    for (const auto& pair : mp)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
            val = pair.first;
        }
    }
    return val;
}
char found_max_character(char* s)
{
    int len = strlen(s);
    map<char, int> mp;
    for (int i = 0; i < len; ++i)
    {
        mp[s[i]]++;
    }
    int maxap = 0;
    char v = '\0';
    for (const auto& pair : mp)
    {
        if (pair.second > maxap)
        {
            maxap = pair.second;
            v = pair.first;
        }
    }
    return v;
}
/*
    m?ng ?ánh d?u
    vector<int> a={1,2,3,4,5,6,76,8,9};
    vector<bool> isProcessed(arr.size(),false);
    for(int i=0; i<a.size();++i)
    {
        if(!isProcessed[i]
        {
            isProcessed[i]=true;
        }
        return 0;
    }*/
bool is_pamgram(char* s)
{
    set<char> se;
    for (int i = 0; i <strlen(s); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            se.insert(s[i] - 'A' + 'a');
        }
        else if ('a' <= s[i] && s[i] <= 'z')
        {
            se.insert(s[i]);
        }
    }
    return se.size() == 26;
}
int different_word_semtence(char* s)
{
    map<char*, int> mp;
    for (int i = 0; i < strlen(s); i++)
    {

    }
}
int main()
{
    /*int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        set<int> s;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
            mp[x]++;
        }
        cout << s.size() << endl;
    }*/
    int T;
    cin >> T;
    int n1, n2;
    cin >> n1 >> n2;
    int* a = new int[n1];
    int* b = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    } 
    set<int> s2;
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
        s2.insert(b[i]);
    }
    bool found = false;
    for (int i = 0; i < n1;i++)
    {
        if (s2.find(a[i]) == s2.end())
        {
            cout << a[i] << " ";
            found = true;
        }
    }
    if (!found)
    {
        cout << "NO FOUND";
    }
    cout << endl;
    delete[] a;
    delete[] b;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
