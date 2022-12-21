#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
int main() {
  int B, E, P, N, M;
  cin >> B >> E >> P >> N >> M;
  vector<vector<int>> ll(N+1);
  for(int i = 0; i < M; i++)
    {
      int x, y;
      cin >> x >> y;
      ll[x].push_back(y);
      ll[y].push_back(x);
    }
  
  long long Bdis[40001];
  int Bv[40001] = {0};
  for(int i = 1; i <= N; i++)
      Bdis[i] = LLONG_MAX;
  queue<int> q;
  Bdis[1] = 0;
  q.push(1);
  while(!q.empty())
    {
      int a = q.front();
      q.pop();
      if(Bv[a]) break;
      Bv[a] = 1;
      for(int e: ll[a])
        {
          if(Bdis[a] + 1 < Bdis[e])
          {
            Bdis[e] = Bdis[a] + 1;
            q.push(e);
          }
        }
    }
  /*for(int i = 1; i <= N; i++)
    cout << Bdis[i] << " ";*/
  
  long long Edis[40001];
  int Ev[40001] = {0};
  for(int i = 1; i <= N; i++)
      Edis[i] = LLONG_MAX;
  Edis[2] = 0;
  q.push(2);
  while(!q.empty())
    {
      int a = q.front();
      q.pop();
      if(Ev[a]) break;
      Ev[a] = 1;
      for(int e: ll[a])
        {
          if(Edis[a] + 1 < Edis[e])
          {
            Edis[e] = Edis[a] + 1;
            q.push(e);
          }
        }
    }

  long long Fdis[40001];
  int Fv[40001] = {0};
  for(int i = 1; i <= N; i++)
      Fdis[i] = LLONG_MAX;
  Fdis[N] = 0;
  q.push(N);
  while(!q.empty())
    {
      int a = q.front();
      q.pop();
      if(Fv[a]) break;
      Fv[a] = 1;
      for(int e: ll[a])
        {
          if(Fdis[a] + 1 < Fdis[e])
          {
            Fdis[e] = Fdis[a] + 1;
            q.push(e);
          }
        }
    }

  long long m = LLONG_MAX;
  for(int i = 1; i <= N; i++)
    {
      long long x = B*Bdis[i] + E*Edis[i] + P*Fdis[i];
      //cout << x << endl;
      if(x < m)
        m = x;
    }
  cout << m;
}