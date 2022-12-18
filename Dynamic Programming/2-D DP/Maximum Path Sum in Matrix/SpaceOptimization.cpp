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

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> dp(m,0);
    for(int i = 0; i < m; i++) dp[i] = matrix[0][i];
    for(int i = 1; i < n; i++)
    {
    	vector<int> curr(m,0);
    	for(int j = 0; j < m; j++)
    	{
    		int up = INT_MIN,left_up = INT_MIN,right_up = INT_MIN;
    		up = dp[j];
    		if(j != 0) left_up = dp[j-1];
    		if(j != m - 1) right_up = dp[j+1];
    		curr[j] = matrix[i][j] + max(up,max(left_up,right_up)); 
    	}
    	dp = curr;
    }
    int maxm = INT_MIN;
    for(int i = 0; i < m; i++) maxm = max(maxm,dp[i]);
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