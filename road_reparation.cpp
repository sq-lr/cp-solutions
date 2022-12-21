#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
vector<vector<pair<int, int>>> llist;
int main() {
  int n, m;
  cin >> n >> m;
  llist.resize(n+1);
  for(int i = 0; i < m; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      llist[x].push_back({y,z});
      llist[y].push_back({x,z});
    }
  
  priority_queue<pair<int,int>> q;
  q.push({0, 1});
  int visited = 0;
  int v[(int)1e5+1] = {0};
  long long sum = 0;
  while(!q.empty())
    {
      if(visited == n)
      {
        cout << sum;
        return 0;
      }
      int a = q.top().second; int b = q.top().first;
      q.pop();
      if(v[a]) continue;
      //cout << a << " ";
      v[a] = 1;
      visited++;
      sum -= b;
      for(auto e: llist[a])
        {
          //cout << e.first << endl;
          q.push({-e.second, e.first});
        }
    }
  cout << -1;
}