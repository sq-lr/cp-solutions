#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, N, rf, rb;
vector<pair<int, int> > v;
int find(int i)
{
    int best = i;
    for(; i < N; i++)
    {
       if(v[i].second >= v[best].second) 
        best = i;
    }
    return best;
}
int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> L >> N >> rf >> rb;
    v.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    long long c = 0;
    int index = 0;
    int last_dest = 0;
    while(index < N)
    {
        index = find(index);
        int dx = v[index].first - last_dest;
        c += (long long)(rf-rb)*dx*v[index].second;
        last_dest = v[index].first;
        index++;
    }
    cout << c;
}