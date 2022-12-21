#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, T;
vector<int> arr;
int calc(int x)
{
    priority_queue<int> q;
    q.push(0);
    int t = 0;
    for(int i = 0; i < N; i++)
    {
        int dum = arr[i];
        if(q.size() >= x) 
        {
            dum -= q.top();
            q.pop();
        }
        if(dum > t) t = dum;
        q.push(-dum);
        //cout << q.top() << endl;
    }
    //cout << endl;
    return t;
}
int main()
{
    cin >> N >> T;
    arr.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    int lo = 1; int hi = T;
    int K = T;
    while(lo <= hi)
    {
        int mid = (lo+hi)/2;
        //cout << mid << endl;
        if(calc(mid) <= T)
        {
            K = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << K;
}