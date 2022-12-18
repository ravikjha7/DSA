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
// Space Complexity : O(n*m)

int GridUniquePaths(int n,int m) {

	vector<vector<int>> dp(n,vector<int>(m,-1));

	// Initialising First Row With 1
	for(int i = 0; i < n; i++) dp[i][0] = 1;

	// Initialising First Column With 1
	for(int i = 0; i < m; i++) dp[0][i] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			// up -> dp[i-1][j]
			// left -> dp[i][j-1]
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	return dp[n-1][m-1];
}

void solve()
{
	int n,m;
	cin >> n >> m;
	cout << GridUniquePaths(n,m) << endl;
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