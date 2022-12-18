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

// No Fixed Ending Point (Variable Ending Point)
// Fixed Starting Point

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++)
	{
		dp[i] = vector<int> (i+1,-1);
	}
	dp[0][0] = triangle[0][0];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(i == 0 && j == 0) continue;
			int up = INT_MAX,left_up = INT_MAX;
			if(j != i) up = triangle[i][j] + dp[i-1][j];
			if(j > 0) left_up = triangle[i][j] + dp[i-1][j-1];
			dp[i][j] = min(up,left_up);
		}
	}
	int minm = INT_MAX;
	for(int i = 0; i < n; i++) minm = min(minm,dp[n-1][i]);
	return minm;
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for(int i = 0; i < n; i++)
	{
		vector<int> temp;
		for(int j = 0; j <= i; j++)
		{
			int r;
			cin >> r;
			temp.push_back(r);
		}
		v.push_back(temp);
	}
	// for(auto i : v)
	// {
	// 	for(auto j : i) cout << j << " ";
	// 	cout << endl;
	// }
	cout << minimumPathSum(v,n) << endl;
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