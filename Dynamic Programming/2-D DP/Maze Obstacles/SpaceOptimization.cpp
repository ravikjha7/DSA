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

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
	vector<int> dp(m,0);
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
    	vector<int> curr(m,0);
    	if(i == 0) curr[0] = 1;
    	for(int j = 0; j < m; j++)
    	{
    		if(i == 0 && j == 0) continue;
    		int left = 0,up = 0;
    		if(i != 0) up = dp[j];
    		if(j != 0) left = curr[j-1];
    		curr[j] = (up+left)%mod;
    		if(mat[i][j] == -1) curr[j] = 0;
    	}
    	dp = curr;
    }
    return dp[m-1];
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < m; j++)
		{
			ll r;
			cin >> r;
			v[i].push_back(r);
		}
	}
	cout << mazeObstacles(n,m,v) << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}