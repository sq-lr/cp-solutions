#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> val(n);
    vector<int> dp(x+1);
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    dp[0] = 1;
    for(int coin: val)
    {
        for(int j = coin; j <= x; j++)
        {
            dp[j] += dp[j-coin];
            dp[j] %= (int)1e9+7;
        }
    }
    cout << dp[x];
}

