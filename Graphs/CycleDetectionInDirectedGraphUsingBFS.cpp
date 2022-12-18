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


// Kahn's Algorithm
// Time Complexity : O(N + E)
// Space Complexity : O(N) + O(N)
// Auxillary Space : O(N)
void bfs(int i,vector<int> adj[],int inDegree[],int &count)
{
	queue<int> q;
	q.push(i);
	while(!q.empty())
	{
		count++;
		int node = q.front();
		q.pop();
		for(auto j : adj[node])
		{
			inDegree[j]--;
			if(!inDegree[j])
			{
				q.push(j);
			}
		}
	}
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	int inDegree[n] = {0};
	for(int i = 0; i < m; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		inDegree[v]++;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(!inDegree[i])
		{
			bfs(i,adj,inDegree,count);
		}
	}
	cout << count << endl;
	if(count == n) cout << "NO" << endl;
	else cout << "YES" << endl;
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