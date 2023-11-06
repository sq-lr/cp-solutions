#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int> > llist;
vector<bool> v;

pair<int,int> dp(int x)
{
    pair<int, int> ans = make_pair(0, 0);
    if(llist[x].size() == 1) return ans;
    v[x] = 1;
    int m = INT_MIN;
    for(int y: llist[x])
    {
        if(v[y]) continue;
        pair<int, int> sub_ans = dp(y);
        ans.first += max(sub_ans.first, sub_ans.second);
        m = max(sub_ans.first - max(sub_ans.first, sub_ans.second), m);
    }
    ans.second = ans.first + 1 + m;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    v.resize(n+1);
    llist.resize(n+1);
    llist[1].push_back(1);
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        llist[a].push_back(b);
        llist[b].push_back(a);
    }
    pair<int, int> x = dp(1);
    cout << max(x.first, x.second);
}