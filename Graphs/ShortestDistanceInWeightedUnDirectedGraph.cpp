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

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n+1];
	for(int i = 0; i < m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;
	int dis[n+1] = {0};
	for(int i = 0; i <= n; i++) dis[i] = INT_MAX;
	int source = 1;
	dis[source] = 0;
	q.push({0,source});
	while(!q.empty()) {
		int node = q.top().second;
		int curr_dis = q.top().first;
		q.pop();
		for(auto j : adj[node]) {
			if(curr_dis + j.second < dis[j.first]) {
				dis[j.first] = curr_dis + j.second;
				q.push({dis[j.first],j.first});
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dis[i] << " ";
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