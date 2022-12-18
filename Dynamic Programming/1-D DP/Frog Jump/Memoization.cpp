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

int frogjump(int n, int k, vector<int> &heights, vector<int> &dp)
{
    if(n == 0) return 0;

    if(dp[n] != -1) {
    	// cout << "Time Saved" << endl;
    	return dp[n];
    }
    int minm = INT_MAX;
    for(int i = 1; i <= min(n,k); i++)
    {
    	minm = min(minm,frogjump(n-i,k,heights,dp) + abs(heights[n] - heights[n-i]));
    }
    return minm;
}

int frogJump(int n, int k,vector<int> &heights)
{
    vector<int> dp(n,-1);
    return frogjump(n-1,k,heights,dp);
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