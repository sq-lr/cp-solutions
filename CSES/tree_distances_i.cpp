#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<vector<int> > arr;
vector<int> d;
vector<int> v;

int fnode(int x)
{
	vector<int> v(n+1);
	queue<int> q;
	q.push(x);
	v[x] = 1;
	int y;
	while(!q.empty())
	{
		y = q.front();
		for(int z: arr[y])
		{
			if(!v[z])
			{
				v[z] = 1;
				q.push(z);
			}
		}
		q.pop();
	}
	return y;
}

void distance(int node, int val)
{
	v[node] = 1;
	for(int x: arr[node])
	{
		if(!v[x])
		{
			d[x] = max(d[x], val+1);
            distance(x, val+1);
		}
	}
	v[node] = 0;
}

int main() {
	cin >> n;
	arr.resize(n+1);
	d.resize(n+1);
	v.resize(n+1);
	for(int i = 0; i < n-1; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int d1 = fnode(1);
	int d2 = fnode(d1);
	distance(d1, 0);
	distance(d2, 0);
    for(int i = 1; i < n+1; i++)
	{
		cout << d[i] << " ";
	}
}
