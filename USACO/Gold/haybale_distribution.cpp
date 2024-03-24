#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> barns(n);
    for(int i = 0; i < n; i++)
    {
        cin >> barns[i];
    }
    sort(barns.begin(), barns.end());
    vector<long long> psum(n);
    for(int i = 1; i < n; i++)
    {
        psum[i] = psum[i-1] + (barns[i]-barns[i-1])*i;
    } 
    vector<long long> ssum(n);
    for(int i = n-2; i >= 0; i--)
    {
        int num_right = n-1-i;
        ssum[i] = ssum[i+1] + (barns[i+1]-barns[i])*num_right;
    }
    int q;
    cin >> q;
    while(q--)
    {
        long long a, b;
        cin >> a >> b;
        int i = n*b/(a+b);
        cout << psum[i]*a + ssum[i]*b << "\n";
    }
}