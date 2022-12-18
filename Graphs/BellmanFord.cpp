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

// Bellman Ford Algorithm
// Used To Find Shortest Paths Of All Nodes From Source Node
// If There Is A Negative Edge, It Will Detect It
// Works For Directed Graph
// In Case Of Undirected Graph, We will convert into Directed Graph with BiDirectional Edges

// Algorithm : 
// Perform Relaxation N - 1 times
// Relaxation : 
// if(dis[u] + wt < dis[v]) 
//     dis[v] = dis[u] + wt;

// Time Complexity : O(N-1)*O(E)

struct node{
	int u,v,w;
	node(int uu,int vv,int ww)
	{
		u = uu;
		v = vv;
		w = ww;
	}
};

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<node> edges;
	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back(node(u,v,w));
	}
	int src;
	cin >> src;
	vector<int> dis(n,INT_MAX);

	dis[src] = 0;

	for(int i = 0; i < n-1; i++)
	{
		for(auto it : edges)
		{
			if(dis[it.u] + it.w < dis[it.v])
			{
				dis[it.v] = dis[it.u] + it.w;
			}
		}
	}
	for(auto it : edges)
	{
		if(dis[it.u] + it.w < dis[it.v])
		{
			cout << "Negative Cycle Found" << endl;
			return;
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout << i << " " << dis[i] << endl;
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