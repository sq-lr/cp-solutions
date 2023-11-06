#include <iostream>
#include <stack>
#include <vector>
#define INF 5e12+1
using namespace std;
struct Edge
{
    int a, b, c;
    Edge(int x, int y, int z)
    {
        a = x;
        b = y; 
        c = z;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back(Edge(a, b, c));
    }

    vector<long long> d(n+1);
    vector<int> p(n+1, -1);
    int u;
    for (int i = 0; i < n; ++i) {
        u = -1;
        for (Edge x : e) {
            if (d[x.a] + x.c < d[x.b]) {
                d[x.b] = d[x.a] + x.c;
                p[x.b] = x.a;
                u = x.b;
            }
        }
    }

    if (u == -1) {
        cout << "NO";
        return 0;
    } 
    for (int i = 0; i < n; ++i)
    {     
        u = p[u];
    }
    vector<int> ans;
    for(int v = u;; v = p[v]) {
        ans.push_back(v);
        if (v == u && ans.size() > 1)
            break;
    }
    
    cout << "YES" << " ";
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << " ";
}