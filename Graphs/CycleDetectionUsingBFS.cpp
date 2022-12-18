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

bool detect(int src, int vis[], vector<int> adj[]) {
        queue<pair<int, int>> q;

	q.push({src, -1});
	vis[src] = 1;

	while(!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();

		for(auto i : adj[node.first]) {
			if(vis[i] == 0) {
				q.push({i, node.first});
				vis[i] = 1;
			} else if(i != node.second || node.second == -1) return true;
		}

	}

// 	cout << "Cycle Not Found" << endl;
    return false;
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
	for(int i = 1; i <= n; i++) {
	    if(vis[i] == 0) {
	        if(detect(i, vis, adj)) {
	        	cout << "Cycle Found" << endl;
	        	return;
	        }
	    }
	}

	cout << "Cycle Not Found" << endl;

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