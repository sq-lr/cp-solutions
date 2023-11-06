#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dp[(int)1e6 + 1];
    for(int i = 0; i <= n; i++)
        dp[i] = (int)1e6;
    
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = i;
        while(x != 0)
        {
            int dig = x%10;
            x /= 10;
            dp[i] = min(dp[i], dp[i-dig] + 1);
        }
    }
    cout << dp[n];
}

