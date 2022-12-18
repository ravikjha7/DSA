#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
	int n,m;
	cin >> n >> m;

	// Creating The Graph
	vector<pair<int,int>> adj[n];
	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int dis[n];
	for(int i = 0; i < n; i++)
	{
		dis[i] = INT_MAX;
	}
	// cout << "Done!!!" << endl;
	// for(int i = 0; i < n; i++)
	// {
		queue<int> q;
		q.push(0);
		dis[0] = 0;
		while(!q.empty())
		{
			int node = q.front();
			q.pop();
			int curr_dis = dis[node];
			for(auto j : adj[node])
			{
				if(dis[j.first] > curr_dis + j.second)
				{
					dis[j.first] = curr_dis + j.second;
					q.push(j.first);
				}
			}
		}
		for(ll i = 0; i < n; i++)
		{
			cout << dis[i] << " ";
		}
		cout << endl;
	// }
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}