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

bool CheckCycleDFS(vector<int> adj[],int vis[],int dfsvis[],int i,int n)
{
	vis[i] = 1;
	dfsvis[i] = 1;
	for(auto j : adj[i])
	{
		if(!vis[j])
		{
			if(CheckCycleDFS(adj,vis,dfsvis,j,n)) return true;
		}
		else if(dfsvis[j]) return true;
	}
	dfsvis[i] = 0;
	return false;
}

bool CheckCycle(vector<int> adj[],int n,int m)
{
	int vis[n+1] = {0};
	int dfsvis[n+1] {0};
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			if(CheckCycleDFS(adj,vis,dfsvis,i,n)) return true;
		}
	}
	return false;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	if(CheckCycle(adj,n,m)) cout << "Cycle Found !!!" << endl;
	else cout << "Cycle Not Found !!! " << endl;
	return 0;
}