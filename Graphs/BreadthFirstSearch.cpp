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

vector<int> bfs(vector<int> adj[],int n)
{
	int vis[n+1] = {0};
	queue<int> q;
	vector<int> ans;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			q.push(i);
			ans.push_back(i);
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				for(auto i : adj[node])
				{
					if(vis[i] == 0)
					{
						vis[i] = 1;
						q.push(i);
						ans.push_back(i);
					}
				}
			}
		}
	}
	return ans;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i = 1; i <= n; i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans = bfs(adj,n);
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