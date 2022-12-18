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

// Memoization : Top To Bottom Approach
// TC : O(N)
// SC : O(N) + O(N)
int f(int n,vector<int> &dp)
{
	// Base Case
	if(n <= 1) return n;

	// If Value of dp[n] is precomputed
	// We will directly return it
	if(dp[n] != -1) return dp[n];

	// Storing and Returning dp[n]
	return dp[n] = f(n-1,dp) + f(n-2,dp); 
}


void solve()
{
	int n;
	cin >> n;
	vector<int> dp(n+1,-1);
	cout << f(n,dp) << endl;
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