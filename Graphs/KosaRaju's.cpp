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

// Kosaraju's Algorithm
// Step 1 : Topo Sort
// Step 2 : Transpose The Graph
// Step 3 : DFS Sorted Graph

void dfs(vector<int> adj[], int node, int vis[],stack<int> &s)
{
	vis[node] = 1;
	for(auto i : adj[node])
	{
		if(!vis[i])
		{
			dfs(adj,i,vis,s);
		}
	}
	s.push(node);
}

void topo(vector<int> adj[],int n,int vis[],stack<int> &s)
{
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(adj,i,vis,s);
		}
	}
}

void dfs2(vector<int> adj[], int node, int vis[])
{
	vis[node] = 1;
	cout << node << " ";
	for(auto i : adj[node])
	{
		if(!vis[i])
		{
			dfs2(adj,i,vis);
		}
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
	}
	int vis[n+1] = {0};
	stack<int> s;
	topo(adj,n,vis,s);
	vector<int> transpose[n+1];
	for(int i = 1; i <= n; i++)
	{
		for(auto j : adj[i])
		{
			transpose[j].push_back(i);
		}
	}
	for(int i = 1; i <= n; i++) vis[i] = 0;
	while(!s.empty())
	{
		int node = s.top();
		s.pop();
		if(!vis[node])
		{
			dfs2(transpose,node,vis);
			cout << endl;
		}
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