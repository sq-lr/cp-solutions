#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n;
vector<vector<long long> > arr;
vector<long long> d;
vector<long long> x;
long long counter;
long long mdepth = 0;
void dfs(long long node, long long depth)
{
    //cout << node << "\n";
    d[node] = depth;
    x[node] = counter;
    mdepth = max(mdepth, depth);
    counter--;
    for(int i = arr[node].size()-1; i>=0; i--)
        dfs(arr[node][i], depth+1);
}
int main()
{
    cin >> n;
    arr.resize(n+2);
    d.resize(n+2);
    x.resize(n+2);
    counter = n; 
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x+1].push_back(i+1);
    }
    for(int i = 1; i <= n+1; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    dfs(n+1, 0);
    cout << n+1;
    for(int i = 1; i <= n; i++)
        cout << "\n" << x[i] + (mdepth-d[i])*(n+1);
}