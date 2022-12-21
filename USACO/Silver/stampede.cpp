#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
    /*freopen("stampede.in", "r", stdin);
    freopen("stampede.out", "w", stdout);*/
    int n;
    cin >> n;
    vector<pair<int, pair<int, int> > > arr(n);
    set<int> t;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = make_pair(b, make_pair((-a-1)*c, -a*c));
        t.insert(-a*c);
        t.insert((-a-1)*c);
    }
    sort(arr.begin(), arr.end());
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        auto it1 = t.lower_bound(arr[i].second.first);
        auto it2 = t.lower_bound(arr[i].second.second);
        if(it1 != it2)
        {
            count++;
            t.erase(it1, it2);
        }
    }
    cout << count;
}