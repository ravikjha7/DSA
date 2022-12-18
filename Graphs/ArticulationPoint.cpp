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

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &articulation) 
{
	vis[node] = 1;
	tin[node] = low[node] = timer++;
	int child = 0;
	for(auto it : adj[node])
	{
		if(it == parent) continue;
		if(!vis[it]) {
			child++;
			dfs(it, node, vis, tin, low, timer, adj,articulation);
			low[node] = min(low[node],low[it]);
			if(low[it] >= tin[node] && parent != -1) {
				articulation[node] = 1;
			}
		}
		else {
				low[node] = min(low[node],tin[it]);
		}
	}

	if(parent == -1 && child > 1) {
		articulation[node] = 1;
	}
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	while(m--)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> tin(n+1, -1);
	vector<int> low(n+1, -1); 
	vector<int> vis(n+1, 0); 	
	int timer = 0;
	vector<int> articulation(n+1,0);
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) {
			dfs(i, -1, vis, tin, low, timer, adj,articulation);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(articulation[i] == 1) cout << i << endl;
	}
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