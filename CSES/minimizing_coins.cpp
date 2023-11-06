#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[(int)1e6+1];
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i <= x; i++)
        dp[i] = (int)1e8 + 1;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    for(int i = 0; i <= x; i++)
    {
        for(int coin: arr)
        {
            if(i-coin >= 0 && dp[i-coin] != (int)1e8+1)
                dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }
    cout << (dp[x] == (int)1e8 + 1 ? -1: dp[x]);
}
