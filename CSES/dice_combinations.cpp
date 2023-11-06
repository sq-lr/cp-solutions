#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1);
    arr[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i-6; j < i; ++j)
        {
            if(j < 0) continue;
            arr[i] = (arr[i] + arr[j])%(int)(1e9+7);
        }
    }
    cout << arr[n];
}