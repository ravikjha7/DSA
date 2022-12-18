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

// Tabulation : Bottom To Up Approach
// TC : O(N)
// SC : O(N)
void solve()
{
	int n;
	cin >> n;
	vector<int> dp(n+1,-1);
	// Base Cases Directly
	dp[0] = 0, dp[1] = 1;	
	for(int i = 2; i <= n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n] << endl;
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