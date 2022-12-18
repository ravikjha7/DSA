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

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	return (a / gcd(a,b)) * b;
}

// Space Complexity : O(N)
// Time Complexity : O(N + 2E)

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ans) {
	vis[node] = 1;
	ans.push_back(node);

	for(auto i : adj[node]) {
		// cout << i << " " << node << endl;
		if(vis[i] == 0) {
			dfs(i, adj, vis, ans);
		}
	}

}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> adj[n + 1];
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int vis[n + 1] = {0};

	vector<int> ans;

	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			dfs(i, adj, vis, ans);
		}
	}

	for(auto i : ans) cout << i << " ";
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