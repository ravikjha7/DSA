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

void solve()
{
	int n;
	cin >> n;
	int par[n+1];
	int rank[n+1] = {0};
	for(int i = 1; i <= n; i++) par[i] = i;
	int m;
	cin >> m;
	while(m--)
	{
		int u,v;
		cin >> u >> v;
		union2(u,v,par,rank);
	}
	// To Check Whether Two Nodes Belong To Same Component Or Not
	int a,b;
	cin >> a >> b;
	if(rank[findPar(a,par)] == rank[findPar(b,par)]) {
		cout << "Same Component" << endl;
	} else {
		cout << "Different Component" << endl;
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