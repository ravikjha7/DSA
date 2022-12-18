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

bool BiPartiteUsingDFS(vector<int> adj[],int i,int n, int par,int color[])
{
	for(auto j : adj[i])
	{
		if(color[j] != par)
		{
			if(color[j] == -1)
			{
				color[j] = (par + 1) % 2;
				if(!BiPartiteUsingDFS(adj,j,n,color[j],color))
				return false;
			}
		}
		else return false;
	}
	return true;
}

bool BiPartite(vector<int> adj[],int n, int m)
{
	int color[n+1];
	for(int i = 0; i <= n; i++) color[i] = -1;
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == -1)
		{
			color[i] = 0;
			if(!BiPartiteUsingDFS(adj,i,n,0,color)) return false;
		}
	}
	return true;
}

int main()
{
	file();
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	if(BiPartite(adj,n,m)) cout << "BiPartite" << endl;
	else cout << "Not BiPartite" << endl;
	return 0;
}