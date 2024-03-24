#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long double,int> pp;
const int mod = 1000000007;

int g[305][305];
int dp[305][305];
int main()
{
    int n;
    cin >> n;
    vector<long double> a(n+1,0);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<long double> b(n+1,0);
    for(int i = 1; i <= n; i++)
        cin >> b[i];

    for(int i = 1; i <= n; i++)
        a[i] += a[i-1];
    for(int i = 1; i <= n; i++)
        b[i] += b[i-1];

    vector<vector<pp> > va(n+1,vector<pp>());
    vector<vector<pp> > vb(n+1,vector<pp>());
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) va[i].push_back(pp((a[i]-a[j])/(i-j),i-j));
        sort(va[i].begin(),va[i].end());
        // for (auto x:va[i]) cout<<x.first<<' '<<x.second<<endl;
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) vb[i].push_back(pp((b[i]-b[j])/(i-j),i-j));
        sort(vb[i].begin(),vb[i].end());
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            g[j][0] = dp[i - va[i][0].second][j];
            for (int k = 1; k < i; k++)
                g[j][k] = (g[j][k - 1] + dp[i - va[i][k].second][j]) % mod;
        }
        for (int j = 1; j <= n; j++)
        {
            int p = -1;
            for (int k = 0; k < j; k++)
            {
                while (p + 1 < i && va[i][p + 1].first <= vb[j][k].first+1e-13)
                    p++;
                // if (j<vb[j][k].second) cout<<"SDA";
                dp[i][j] = (dp[i][j] + g[j - vb[j][k].second][p]) % mod;
                // cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
                // cout<<i<<' '<<j<<' '<<g[j - vb[j][k].second][p]<<endl;
            }
        }
    }    
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }*/
    cout << dp[n][n];
}