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

int minSumPath(vector<vector<int>> &grid) 
{
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<int>> dp(n,vector<int> (m,0));
	dp[0][0] = grid[0][0];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i == 0 && j == 0) continue;
			int left = INT_MAX;
			int up = INT_MAX;
			if(i > 0) up = dp[i-1][j];
			if(j > 0) left = dp[i][j-1];
			dp[i][j] = min(left,up) + grid[i][j];
		}
	}
	return dp[n-1][m-1];
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	cout << minSumPath(v) << endl;
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