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

int MaximumNonAdjacentSum(vector<int> &arr,int n)
{
	vector<int> dp(n,0);
	dp[0] = arr[0];
	dp[1] = max(arr[0],arr[1]);
	for(int i = 2; i < n; i++)
	{
		dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
	}
	return dp[n-1];
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << MaximumNonAdjacentSum(arr,n) << endl;
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