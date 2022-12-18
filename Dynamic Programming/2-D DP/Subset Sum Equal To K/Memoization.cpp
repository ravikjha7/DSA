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

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	return (a / gcd(a,b)) * b;
}

// Time Complexity : O(N*target)
// Space Complexity : O(N*target) + O(N)

bool subsetsumtok(int n,int target,vector<int> &arr,vector<vector<int>> &dp) {
	// If Target Has Become Negative, it is not possible to find target
	if(target < 0) return false;
	if(target == 0) return true;
	if(n == 0) return (arr[0] == target);

	if(dp[n][target] != -1) return dp[n][target];
	bool take = subsetsumtok(n - 1, target - arr[n],arr,dp);
	bool nottake = subsetsumtok(n - 1,target,arr,dp);
	return dp[n][target] = (take | nottake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n + 1,vector<int> (k + 1,-1));
    return subsetsumtok(n - 1,k,arr,dp);
}

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << subsetSumToK(n,k,arr) << endl;
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