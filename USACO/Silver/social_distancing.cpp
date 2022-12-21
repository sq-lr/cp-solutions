#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int N, M;
vector<pair<long long, long long> > field;
long long calc(long long dis)
{
    long long loc = LLONG_MIN;
    long long count = 0;
    for(int i = 0; i < M; i++)
    {
        if(field[i].first > loc) loc = field[i].first;
        long long end = field[i].second;
        while(loc <= end)
        {
            //cout << loc << " ";
            count++;
            loc += dis;
        }
    }
    //cout << endl;
    return count;
}
int main()
{
    /*freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);*/
    cin >> N >> M;
    field.resize(M);
    for(int i = 0; i < M; i++)
    {
        cin >> field[i].first >> field[i].second;
    }
    sort(field.begin(), field.end());
    long long lo = 1; long long hi = (long long)1e18;
    long long max = 0;
    while(lo <= hi)
    {
        long long mid = (lo + hi)/2;
        //cout << mid << " ";
        if(calc(mid) >= N)
        {
            if(mid > max) max = mid;
            lo = mid + 1;
        }
        else hi = mid-1;
    }
    cout << max;
}