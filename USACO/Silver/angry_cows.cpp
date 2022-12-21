#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int hay[50000];
bool calc(int x)
{
    int index = 0;
    int count = 0;
    while(count < K && index < N)
    {
        int pos = hay[index]+x;
        while(index < N && hay[index] <= pos+x)
            index++;
        count++;
    }
    if(index == N) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> hay[i];
    sort(hay, hay+N);
    int lo = 0; int hi = 500000000;
    int r;
    while(lo <= hi)
    {
        int mid = (lo + hi)/2;
        if(calc(mid))
        {
            r = mid;
            hi = mid-1;
        }
        else lo = mid+1; 
    }
    cout << r;
}