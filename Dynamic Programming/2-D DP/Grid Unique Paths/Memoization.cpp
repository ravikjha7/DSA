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

// Time Complexity : O(n*m)
// Space Complexity : O(n-1+m-1) + O(n*m)

int GridUniquePaths(int i,int j,vector<vector<int>> &dp) {
	if(i == 0 || j == 0) {
		return 1;
	}

	if(dp[i][j] != -1) return dp[i][j];

	int left = GridUniquePaths(i-1,j,dp);
	int up = GridUniquePaths(i,j-1,dp);

	// Storing No Of Ways From That Point
	return dp[i][j] = left + up;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	int count = 0;
	vector<vector<int>> dp(n,vector<int>(m,-1));
	cout << GridUniquePaths(n-1,m-1,dp) << endl;
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