#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > llist;
vector<int> h;
vector<bool> v;
int height(int node)
{
    if(llist[node].size() == 1) return 0;
    if(h[node]) return h[node];
    v[node] = 1;
    for(int x: llist[node])
    {
        if(v[x]) continue;
        h[node] = max(h[node], height(x)+1);
    }
    v[node] = 0;
    return h[node];
}
pair<int, int> diameter(int node)
{
    pair<int, int> ans = make_pair(0, 0);
    if(llist[node].size() == 1) return ans;
    v[node] = 1;
    int mh1, mh2;
    mh1 = mh2 = 0;
    for(int x: llist[node])
    {
        if(v[x]) continue;
        pair<int, int> sub_ans = diameter(x);
        int mh = height(x);
        ans.second = max(ans.second, max(sub_ans.first, sub_ans.second));
        if(mh >= mh1)
        {
            mh2 = mh1;
            mh1 = mh;
        }
        else if(mh >= mh2)
        {
            mh2 = mh;
        }
    }
    if(llist[node].size() == 2) ans.first = mh1 + mh2 + 1;
    else ans.first = mh1 + mh2 + 2;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    v.resize(n+1);
    h.resize(n+1);
    llist.resize(n+1);
    llist[1].push_back(1);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        llist[a].push_back(b);
        llist[b].push_back(a);
    }
    pair<int, int> d = diameter(1);
    cout << max(d.first, d.second);
}