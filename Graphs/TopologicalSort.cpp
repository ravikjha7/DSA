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

void dfs(int i,vector<int> adj[],int vis[],stack<int>& s)
{
	vis[i] = 1;
	for(auto j : adj[i])
	{
		if(!vis[j])
		{
			dfs(j,adj,vis,s);
		}
	}
	s.push(i);
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	int vis[n] = {0};
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			dfs(i,adj,vis,s);
		}
	}
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
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