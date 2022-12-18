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

int findPar(int node, int par[])
{
	// Ultimate Parent will have parent has it only
	if(par[node] == node) return node;

	// Path Compression
	par[node] = findPar(par[node],par);
	return par[node];
}

void union2(int u,int v,int par[],int rank[])
{
	u = findPar(u,par);
	v = findPar(v,par);
	if(rank[u] < rank[v]) {
		par[u] = par[v];
	} else if(rank[v] < rank[u]) {
		par[v] = par[u];
	} else {
		par[v] = par[u];
		// Rank Will Be Updated Only If Rank Of Parents Were Same
		rank[u]++;
	}
}

class Node
{
	public :
		int u,v,w;
	Node(int u1,int v1,int w1) {
		u = u1;
		v = v1;
		w = w1;
	}
};

bool comp(Node &a,Node &b)
{
	return a.w < b.w;
}

void solve()
{
	int n, m; 
	cin >> n >> m;
	vector<Node> edges;
	int par[n+1];
	int rank[n+1] = {0};
	for(int i = 1; i <= n; i++) par[i] = i;
	int temp = m;
	while(temp--)
	{
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back(Node(u,v,w));
	}
	sort(edges.begin(),edges.end(),comp);
	vector<pair<int,int>> mst; 
	ll cost = 0;
	for(int i = 0; i < m; i++)
	{
		if(findPar(edges[i].u,par) != findPar(edges[i].v,par))
		{
			cost += edges[i].w;
			mst.push_back({edges[i].u,edges[i].v});
			union2(edges[i].u,edges[i].v,par,rank);
		}
	}
	cout << "Cost : " << cost << endl;
	for(auto i : mst)
	{
		cout << i.first << " -> " << i.second << endl;
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