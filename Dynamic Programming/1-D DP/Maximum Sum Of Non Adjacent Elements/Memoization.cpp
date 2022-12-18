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

int MaximumNonAdjacentSum(int arr[],int n,vector<int> &dp,int i)
{
	if(i < 0) return 0;
	if(i == 0) return arr[0];

	if(dp[i] != -1) return dp[i];

	int take = arr[i] + MaximumNonAdjacentSum(arr,n,dp,i-2);
	int nottake = MaximumNonAdjacentSum(arr,n,dp,i-1);

	return dp[i] = max(take,nottake);
}

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> dp(n,-1);
	cout << MaximumNonAdjacentSum(arr,n,dp,n-1) << endl;
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