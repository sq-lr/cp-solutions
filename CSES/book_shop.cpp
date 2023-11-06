#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    int w[1001] = {0};
    int v[1001] = {0};
    for(int i = 1; i <= n; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    int num[(int)1e5+1] = {0};
    for(int i = 0; i <= n; i++)
    {
        for(int j = x; j >= 0; j--)
        {
            if(j - w[i] >= 0) num[j] = max(num[j], num[j - w[i]] + v[i]);
        }
    }
    cout << num[x];
}