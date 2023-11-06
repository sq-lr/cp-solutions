#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int w[100];
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    bool dp[(int)1e5+1] = {0};
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = (int)1e5; j >= w[i]; j--)
        {
            dp[j] = dp[j] || dp[j-w[i]];
        }
    }
    int c = 0;
    queue<int> q;
    for(int i = 1; i < (int)1e5+1; i++)
    {
        if(dp[i])
        {
            c++;
            q.push(i);
        }
    }
    cout << c << endl;
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}