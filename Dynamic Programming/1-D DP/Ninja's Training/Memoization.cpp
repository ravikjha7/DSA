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

int helper(vector<vector<int>> &arr,vector<vector<int>> &dp,int i,int j)
{
	if(i == 0) {
		int maxm = 0;
		for(int k = 0; k < 3; k++)
		{
			if(k != j) maxm = max(maxm,arr[0][k]);
		}
		return maxm;
	}
	if(dp[i][j] != -1) return dp[i][j];
	int maxm = 0;
	for(int k = 0; k < 3; k++)
	{
		if(k != j) 
		{
			int curr = arr[i][k] + helper(arr,dp,i-1,k);
			maxm = max(maxm,curr);
		}
	}
	return dp[i][j] = maxm;
}

int ninjaTraining(int n, vector<vector<int>> &arr)
{
	vector<vector<int>> dp(n, vector<int>(4,-1));
    return helper(arr,dp,n-1,3);
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for(int i = 0; i < n; i++)
	{
		vector<int> temp;
		for(int j = 0; j < 3; j++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	cout << ninjaTraining(n,v) << endl;
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