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

int frogJump(int n, int k, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2; i < n; i++)
    {
    	dp[i] = INT_MAX;
    	for(int j = 1; j <= min(k,i); j++)
    	{
    		dp[i] = min(dp[i],dp[i-j] + abs(heights[i] - heights[i-j]));
    	}
    }
    return dp[n-1];
}

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> heights(n,0);
	// vector<int> dp(n,-1);
	for(int i = 0; i < n; i++) cin >> heights[i];
	cout << frogJump(n,k,heights) << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}