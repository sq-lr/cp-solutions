#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    map<int, int> m;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        m[b] = a;
    }

    /*for(auto it = m.begin(); it != m.end(); it++)
        cout << " " << it -> first << " " << it -> second << endl;*/
        
    auto lo = m.begin();
    auto hi = m.end();
    hi--;
    int t = 0;
    while(lo != hi)
    {
        t = max(lo->first + hi->first, t);
        //cout << lo -> first << " " << hi-> first << endl;
        int tosub = min(lo->second, hi->second);
        lo->second -= tosub;
        hi->second -= tosub;
        if(lo->second == 0) lo++;
        if(hi->second == 0) hi--;
    }
    if(lo->second != 0) t = max(2*lo->first, t);
    cout << t;
}