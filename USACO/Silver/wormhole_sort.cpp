#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> pos;
vector<vector<pair<int, int> > > arr;
struct DSU
{
    vector<int> e;
    DSU(int N) {e = vector<int>(N+1, -1);}

    int get(int x){return e[x] < 0 ? x : e[x] = get(e[x]);} 
    
    bool same_set(int a, int b){return get(a) == get(b);}

    int size(int x){return -e[get(x)];}

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

bool trie(int x)
{
    DSU dsu(N);
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j].second >= x) 
                dsu.unite(i, arr[i][j].first);
        }
    }

    for(int i = 1; i <= N; i++)
    {
        if(pos[i] != i && !dsu.same_set(pos[i], i))
            return false;
    }
    return true;
}

int main()
{
    cin >> N >> M;
    pos.resize(N+1);
    arr.resize(N+1);
    for(int i = 1; i <= N; i++)
        cin >> pos[i];
    for(int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(b, c));
        arr[b].push_back(make_pair(a, c));
    }
    bool flag = true;
    for(int i = 1; i <= N; i++)
    {
        if(pos[i] != i)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << -1;
        return 0;
    }
    int lo = 1; int hi = (int)1e9;
    int m = (int)1e9 + 1;
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        cout << mid << endl;
        if(trie(mid))
        {
            m = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << m << endl;
}