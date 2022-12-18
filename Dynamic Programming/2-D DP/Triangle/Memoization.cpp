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

int minimumpathsum(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>> &dp)
{
	if(i == n) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	int down = triangle[i][j] + minimumpathsum(triangle,i+1,j,n,dp);
	int diagonal = triangle[i][j] + minimumpathsum(triangle,i+1,j+1,n,dp);
	return dp[i][j] = min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++)
	{
		dp[i] = vector<int> (i+1,-1);
	}
	return minimumpathsum(triangle,0,0,n,dp);
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