#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int> > llist;
vector<bool> v;
int sum = -1;
int y;
void dfs(int node, int s)
{
    v[node] = 1;
    if(s > sum)
    {
        sum = s;
        y = node;
    }
    s++;
    for(int x: llist[node])
    {
        if(!v[x]) 
        {
            dfs(x, s);
        }
    }
    v[node] = 0;
}
int main()
{
    int n;
    cin >> n;
    llist.resize(n+1);
    v.resize(n+1);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        llist[a].push_back(b);
        llist[b].push_back(a);
    }
    dfs(1, 0);
    sum = 0;
    dfs(y, 0);
    cout << sum;
}