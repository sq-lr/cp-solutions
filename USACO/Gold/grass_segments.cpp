#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> m;
vector<long long> seg;
int seg_size;
void update(int cur, int d)
{
    for (int i = seg_size + cur; i > 0; i >>= 1)
    {
        seg[i] += d;
    }
}
long long sum(int lo, int hi)
{
    if (lo>hi-1) return 0;
    long long s = 0;
    if (lo == hi)
        return seg[lo + seg_size];
    for (lo += seg_size, hi += seg_size; lo < hi; lo >>= 1, hi >>= 1)
    {
        if (lo & 1)
        {
            // cout << lo << " ";
            s += seg[lo++];
        }
        if (hi & 1)
        {
            s += seg[--hi];
            // cout << hi << " ";
        }
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(4));
    // left, right, k, i
    vector<vector<int> > length(n, vector<int>(3));
    //-interval length, left, right
    vector<vector<int> > by_k(n, vector<int>(4));
    //-k, left, right, id
    vector<int> points;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][3] = i;
        length[i][0] = arr[i][0] - arr[i][1];
        length[i][1] = arr[i][0];
        length[i][2] = arr[i][1];
        by_k[i][0] = -arr[i][2];
        by_k[i][1] = arr[i][0];
        by_k[i][2] = arr[i][1];
        by_k[i][3] = i;
        points.push_back(arr[i][0]);
        points.push_back(arr[i][0]+1);
        points.push_back(arr[i][1]);
        points.push_back(arr[i][1] - arr[i][2]);
        points.push_back(arr[i][0] + arr[i][2]);
    }
    sort(arr.begin(), arr.end());
    sort(length.begin(), length.end());
    sort(by_k.begin(), by_k.end());
    sort(points.begin(), points.end());

    int cur = 1;
    for (int i = 0; i < points.size(); i++)
    {
        if (!m[points[i]])
        {
            m[points[i]] = cur;
            cur++;
        }
        // cout << points[i] << " " << m[points[i]] << "\n";
    }

    // ones to right of left
    seg.resize(2 * cur + 2);
    seg_size = cur;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int k = -by_k[i][0];
        // cout << k << "\n";
        while (index < n && -length[index][0] >= k)
        {
            // cout << i << " " << length[index][1] << "\n";
            update(m[length[index][1]], 1);
            /*for(int i = 1; i <= seg_size; i++)
            {
            cout << seg[i+seg_size];
            }
            cout << "\n";*/
            index++;
        }
        ans[by_k[i][3]] += sum(m[by_k[i][1]+1], m[by_k[i][2] - k] + 1);
        // cout<<"$: "<<by_k[i][1]<<' '<<by_k[i][2]<<endl;
        // cout<<"$: "<<m[by_k[i][1]+1]<<' '<<m[by_k[i][2]-k]<<endl;
        // cout<<"#:  "<< sum(2, m[by_k[i][2] - k] + 1)<<endl;

        // cout << by_k[i][2] - k << "\n";
        // cout << m[by_k[i][1]] << " " << m[by_k[i][2]-k] << " " << ans[by_k[i][3]] << "\n";
    }

    // // ones to left and surrounding
    index = 0;
    vector<long long> seg2(2 * cur + 2);
    vector<int> tracker(cur + 1);
    seg = seg2;
    for (int i = 0; i < n; i++)
    {
        while (index < n && arr[index][0]<=arr[i][0]) {
            update(m[arr[index][1]], 1);
            index++;
        }
        ans[arr[i][3]] += sum(m[arr[i][0] + arr[i][2]], seg_size + 1);
        // cout << arr[i][0]+arr[i][2] << " " << sum(m[arr[i][0]+arr[i][2]], seg_size+1) << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] -1 << "\n";
    }
}
