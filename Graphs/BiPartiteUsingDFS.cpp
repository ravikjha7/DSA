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

bool dfs(int node, int vis[], vector<int> adj[], int col) {
	vis[node] = col;

	for(auto i : adj[node]) {
		if(vis[i] == -1) {
			if(!dfs(i, vis, adj, 1 - col)) return false;
		} else if(vis[i] == col) return false;
	}

	return true;

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
	for(int i = 0; i <= n; i++) vis[i] = -1;

	for(int i = 1; i <= n; i++) {
		if(vis[i] == -1) {
			if(!dfs(i, vis, adj, 0)) {
				cout << "-1" << endl;
				return;
			}
		}
	}

	for(auto i : vis) cout << i << " ";
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