#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > llist;
vector<bool> v;
int sum = 0;
void dfs(int x, int p)
{
    for(int c: llist[x])
    {
        if(c == p) continue;
        dfs(c, x);
        if(v[c] || v[x]) continue;
        v[x] = 1;
        v[c] = 1;
        sum++;
    }
}

int main()
{
    int n;
    cin >> n;
    llist.resize(n+1);
    v.resize(n+1);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        llist[a].push_back(b);
        llist[b].push_back(a);
    }
    dfs(1, 1);
    cout << sum;
}