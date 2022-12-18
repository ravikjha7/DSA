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

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(path length)
//                  : O(N*M) + O(N-1 + M-1)

int minsumpath(vector<vector<int>> &grid,vector<vector<int>> &dp,int i,int j)
{
	if(i == 0 && j == 0) {
		return grid[0][0];
	}
	if(i < 0 || j < 0) {
		return INT_MAX;
	}
	if(dp[i][j] != -1) return dp[i][j];
	int up = minsumpath(grid,dp,i-1,j);
	int left = minsumpath(grid,dp,i,j-1);
	return dp[i][j] = min(up,left) + grid[i][j];
}

int minSumPath(vector<vector<int>> &grid) 
{
	vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size(),-1));
    return minsumpath(grid,dp,grid.size()-1,grid[0].size()-1);
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