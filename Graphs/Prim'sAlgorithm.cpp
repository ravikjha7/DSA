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

// Brute Force Approach
// Time Complexity : O(N^2)
// void solve()
// {
// 	int n,m;
// 	cin >> n >> m;
// 	vector<pair<int,int>> adj[n];
// 	for(int i = 0; i < m; i++)
// 	{
// 		int u,v,w;
// 		cin >> u >> v >> w;
// 		adj[u].push_back({v,w});
// 		adj[v].push_back({u,w});
// 	}
// 	int par[n];
// 	bool mst[n];
// 	int key[n];
// 	for(int i = 0; i < n; i++)
// 	{
// 		par[i] = -1;
// 		mst[i] = false;
// 		key[i] = INT_MAX;
// 	}
// 	key[0] = 0;
// 	for(int i = 0; i < n-1; i++)
// 	{
// 		int minm = INT_MAX,u;
// 		for(int j = 0; j < n; j++)
// 		{
// 			if(mst[j] == false && key[j] < minm)
// 			{
// 				minm = key[j];
// 				u = j;
// 			}
// 		}
// 		mst[u] = true;
// 		for(auto k : adj[u])
// 		{
// 			int node = k.first;
// 			int weight = k.second;
// 			if(mst[node] == false && key[node] > weight)
// 			{
// 				key[node] = weight;
// 				par[node] = u;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < n; i++)
// 	{
// 		cout << par[i] << " - " << i << endl;	
// 	}
// }

// Priority Queue Approach
// Time Complexity : O(nlogn)
// Space Complexity : O(3n)
void solve()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n + 1];
	for(int i = 0; i < m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int par[n + 1];
	bool mst[n + 1];
	int key[n + 1];
	for(int i = 1; i <= n; i++) {
		par[i] = -1;
		mst[i] = false;
		key[i] = INT_MAX;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	key[1] = 0;
	pq.push({0,1});
	for(int i = 0; i < n-1; i++) {
		int u = pq.top().second;
		pq.pop();
		mst[u] = true;
		for(auto k : adj[u]) {
			int node = k.first;
			int weight = k.second;
			if(mst[node] == false && key[node] > weight) {
				key[node] = weight;
				par[node] = u;
				pq.push({weight,node});
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << par[i] << " - " << i << endl;	
	}
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}