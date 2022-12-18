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

bool BiPartite(vector<int> adj[],int n, int m)
{
	int color[n+1];
	for(int i = 0; i <= n; i++) color[i] = -1;
	for(int i = 1; i <= n; i++)
	{
		if(color[i] == -1)
		{
			color[i] = 0 ;
			queue<pair<int,int>> q;
			q.push({i,0});
			while(!q.empty())
			{
				int node = q.front().first;
				int par = q.front().second;
				q.pop();
				for(auto i : adj[node])
				{
					if(color[i] == -1)
					{
						if(par == 0) 
						{
							q.push({i,1});
							color[i] = 1;
						}
						else 
						{
							q.push({i,0});
							color[i] = 0;
						}
					}
					else if(color[i] == par)
					{
						return false;
					}
				}
			}
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