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

// Space Complexity : O(3N)
// Time Complexity : O(N + 2E)

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

	// Define a queue, which will contain Starting Node
	// Make a visited array of size N + 1

	int vis[n + 1] = {0};
	queue<int> q;

	q.push(1);
	vis[1] = 1;

	vector<int> ans;

	while(!q.empty()) {

		int size = q.size();
		
		while(size-- > 0) {
			
			int node = q.front();
			q.pop();

			ans.push_back(node);

			for(auto i : adj[node]) {
				if(vis[i] == 0) {
					q.push(i);
					vis[i] = 1;
				}
			}

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