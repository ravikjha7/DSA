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
	vector<int> dp(m);
	for(int i = 0; i < n; i++)
	{
		vector<int> curr(m,0);
		curr[0] = dp[0] + grid[i][0];
		for(int j = 1; j < m; j++)
		{
			int left = INT_MAX;
			int up = INT_MAX;
			if(i > 0) up = dp[j];
			left = curr[j-1];
			curr[j] = min(left,up) + grid[i][j];
		}
		dp = curr;
	}
	return dp[m-1];
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