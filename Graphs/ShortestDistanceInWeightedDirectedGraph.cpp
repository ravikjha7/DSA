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


void dfs(vector<pair<int,int>> adj[],int vis[],int i,stack<int>& s)
{
	vis[i] = 1;
	for(auto j : adj[i])
	{
		// cout << "Ailaa Jaduu" << endl;
		if(!vis[j.first]) dfs(adj,vis,j.first,s);
	}
	s.push(i);
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
	}

	// Topological Sort
	stack<int> s;
	int vis[n] = {0};
	for(int i = 0; i < n; i++)
	{
		if(!vis[i]) dfs(adj,vis,i,s);
	}

	// Creating Shortest Distance Array
	int dis[n] = {0};
	for(int i = 0; i < n; i++) dis[i] = INT_MAX;
	int source = 0;
	
	// Source Distance Will Obviously Be 0
	dis[source] = 0;

	while(!s.empty())
	{
		int node = s.top();
		s.pop();
		// If dis[node] is INT_MAX, it means it couldn't be reached yet from Source Node
		if(dis[node] != INT_MAX)
		{
			int curr_dis = dis[node];
			for(auto j : adj[node])
			{
				int dist = curr_dis + j.second;
				if(dis[j.first] > dist) {
					dis[j.first] = dist;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) cout << dis[i] << " ";
	cout << endl;
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