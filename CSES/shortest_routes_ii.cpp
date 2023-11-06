#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    long long inf = LLONG_MAX;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long> > arr(n+1, vector<long long>(n+1, inf));
    for(int i = 1; i <= n; ++i)
    {
        arr[i][i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(c < arr[a][b])
            arr[a][b] = arr[b][a] = c;
    }
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(arr[i][k] == inf) continue;
            for(int j = i; j <= n; ++j)
            {
                if(arr[k][j] == inf) continue;
                arr[i][j] = arr[j][i] = min(arr[i][j], arr[i][k] + arr[k][j]); 
            }
        }
    }
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(arr[a][b] == inf) cout << -1 << endl;
        else cout << arr[a][b] << endl;
    }
}