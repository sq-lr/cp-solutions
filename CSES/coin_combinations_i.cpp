#include <iostream>
#include <vector>
using namespace std;
int n;
int m;
vector<int> coin;
vector<int> num;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    coin.resize(n);
    num.resize(m+(int)1e6+1);
    num[0] = 1;
    for(int i = 0; i < n; i++)
        cin >> coin[i];
    for(int i = 0; i < m; i++)
    {
        for(int c: coin)
            num[i+c] = (num[i+c] + num[i])%((int)1e9+7);
    }
    cout << num[m];
}