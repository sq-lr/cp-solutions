#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    
    set<pair<int, int> > s;
    bool turn = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == '0' && b[i] == '1')
        {
            if(s.empty() || !turn)
            {
                s.insert(make_pair(i%k, i));
                turn = 0;
            }
            else {
                auto it = s.lower_bound(make_pair(i%k, 0));
                if(it == s.end())
                    it = s.begin();
                sum += ceil((double)(i-it->second)/k);
                s.erase(it);
            }
        }
        else if(a[i] == '1' && b[i] == '0')
        {
            if(s.empty() || turn)
            {
                s.insert(make_pair(i%k, i));
                turn = 1;
            }
            else {
                auto it = s.lower_bound(make_pair(i%k, 0));
                if(it == s.end())
                    it = s.begin();
                sum += ceil((double)(i-it->second)/k);
                s.erase(it);
            }
        }
        //cout << i << " " << sum << "\n";
    }
    cout << sum;
}