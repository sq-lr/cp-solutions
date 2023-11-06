#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
struct DSU
{
    vector<int> e;
    DSU(int n) 
    {
        e = vector<int>(n+1, -1);
    }
    int get(int x)
    {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    int size(int x)
    {
        return -e[get(x)];
    }
    bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if(x == y) 
            return false;
        if(e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main()
{
    cin >> n >> m;
    int num_comp = n;
    int max_size = 1;
    DSU dsu(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(dsu.unite(a, b))
        {
            num_comp--;
            max_size = max(max_size, dsu.size(a));
        }
        cout << num_comp << " " << max_size << endl;
    }
}