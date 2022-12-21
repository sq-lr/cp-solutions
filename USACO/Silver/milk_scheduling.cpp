#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr(10001);
  for(int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      arr[y].push_back(x);
    }
  priority_queue<int> q;
  int sum = 0;
  for(int i = 10000; i >= 1; i--)
    {
      for(auto x: arr[i])
        q.push(x);
      if(!q.empty())
      {
        sum += q.top();
        q.pop();
      }
    }
  cout << sum;
}