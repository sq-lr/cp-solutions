#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string s, t;
bool arr[18][18];
void calc(int i, int j)
{
    string sn = "";
    string tn = "";
    for(int x = 0; x < s.size(); x++)
    {
        if(s[x] == i+'a' || s[x] == j+'a') sn += s[x];
    }
    for(int x = 0; x < t.size(); x++)
    {
        if(t[x] == i+'a' || t[x] == j+'a') tn += t[x];
    }
    arr[i][j] = (sn == tn);
}
void go()
{
    string req;
    cin >> req;
    for(int i = 0; i < req.size(); i++)
    {
        for(int j = 0; j < req.size(); j++)
        {
            if(!arr[req[i]-'a'][req[j]-'a'])
            {
                cout << "N";
                return;
            }
        }
    }
    cout << "Y";
}
int main()
{
    cin >> s;
    cin >> t;
    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 18; j++)
        {
            calc(i, j);
            //cout << arr[i][j];
        }
        //cout << endl;
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        go();
    }
}