#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n-1);
    for(int i = 0; i < n-1; i++)
        cin >> arr[i];

    vector<vector<long long> > num(n, vector<long long> (n));
    long long ans = 0;
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            if(arr[i][j]-'0' != num[i][i+j+1]%2)
            {
                //cout << i << " " << i+j+1 << ": " << endl;
                ans++;
                num[i][i+j+1]++;
                num[i][i+j+1]%=2;
                for(int k = i+j+1; k < n; k++)
                {
                    /*if(num[i+j+1][k] != 0)
                        cout << i << " " << i+j+1 << " " << k << endl;*/
                    num[i][k] += num[i+j+1][k];
                    num[i][k] %= 2;
                }
            }
        }   
        /*for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
                cout << num[j][k] << " ";
            cout << endl;
        }
        cout << endl;*/
    }
    cout << ans;
}