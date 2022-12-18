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

int getmaxpathsum(vector<vector<int>> &matrix,int i,int j,int n,int m,vector<vector<int>> &dp)
{
	if(j < 0) return INT_MIN;
	if(j == m) return INT_MIN;
	if(i == 0) return matrix[0][j];

	if(dp[i][j] != -1) return dp[i][j];

	int up = getmaxpathsum(matrix,i-1,j,n,m,dp);
	int left_up = getmaxpathsum(matrix,i-1,j-1,n,m,dp);
	int right_up = getmaxpathsum(matrix,i-1,j+1,n,m,dp);
	return dp[i][j] = matrix[i][j] + max(up,max(left_up,right_up));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxm = INT_MIN;
    int curr = 0;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i = 0; i < m; i++)
    {
    	curr = getmaxpathsum(matrix,n-1,i,n,m,dp);
    	maxm = max(maxm,curr);
    }
    return maxm;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cin >> v[i][j];
	}
	cout << getMaxPathSum(v) << endl;
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