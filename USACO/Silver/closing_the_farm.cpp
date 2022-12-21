#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int> > llist;
set<int> s;
int N, M;
struct DSU
{
    vector<int> e;
    DSU(int N) {e = vector<int> (N+1, -1);}
    int get(int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
    int size(int x) {return -e[get(x)];}
    bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if(x == y) return false;
        if(e[x] > e[y])
        {
            int dum = x;
            x = y;
            y = dum;
        }
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

void calc()
{
    DSU dsu(N);
    for(int i = 1; i <= N; i++)
    {
        if(s.find(i) != s.end()) continue;
        for(int j = 0; j < llist[i].size(); j++)
        {
            if(s.find(llist[i][j]) == s.end())
            {
                dsu.unite(i, llist[i][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(s.find(i) == s.end())
        {
            //cout << dsu.size(i) << " " << N-s.size() << endl; 
            if(dsu.size(i) != N - s.size())
            {
                cout << "NO" << endl;
            }
            else cout << "YES" << endl;
            return;
        }
    }
}

int main()
{
    cin >> N >> M;
    llist.resize(N+1);
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        llist[a].push_back(b);
        llist[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        calc();
        int x;
        cin >> x;
        s.insert(x);
    }
}