#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long fact[(int)1e6];
long long inv[(int)1e6];
void factorial()
{
    fact[0] = 1;
    for(long long i = 1; i < (long long)1e6; i++)
    {
        fact[i] = fact[i-1]*i%(long long)(1e9+7);
    }
}
long long ex(long long r, long long p)
{
    if(p == 0) return 1;
    long long x = ex(r, p/2);
    if(p%2 == 0)
        return x*x%(long long)(1e9+7);
    else
        return x*x%(long long)(1e9+7)*r%(long long)(1e9+7);
}
void inverse()
{
    for(long long i = 0; i < (long long)1e6; i++)
    {
        inv[i] = ex(fact[i], (long long)(1e9+5));
    }
}
long long choose(long long n, long long c)
{
    return fact[n]*inv[n-c]%(long long)(1e9+7)*inv[c]%(long long)(1e9+7);
}
int main()
{
    long long n;
    cin >> n;
    factorial();
    inverse();
    vector<long long> arr(n);
    for(long long i = 0; i < n; i++)
        cin >> arr[i];
    
    long long ans = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i+1] > arr[i])
        {
            ans = ans*choose(arr[i+1]/2-1, arr[i]/2-1)%(long long)(1e9+7);
        }
        if(arr[i+1] <= arr[i])
        {
            ans = ans*choose(arr[i]/2, arr[i+1]/2)%(long long)(1e9+7);
        }
    }
    cout << ans << "\n";
}