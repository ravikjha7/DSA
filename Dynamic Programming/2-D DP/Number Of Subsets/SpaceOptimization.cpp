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

int findways(vector<int> &arr,int n,int sum,int tar,vector<vector<int>> &dp) {
	if(n < 0) {
		if(sum == tar) {
			return 1;
		}
		return 0;
	}
	if(dp[n][sum] != -1) return dp[n][sum];
	int take = findways(arr,n - 1,sum + arr[n],tar, dp);
	int nottake = findways(arr,n - 1,sum,tar, dp);
	return dp[n][sum] = take + nottake;	
}

int findWays(vector<int> &arr,int tar) {
	int n = arr.size(); 
	vector<int> dp(tar + 1,0);
    dp[0] = 1;
	if(arr[0] <= tar) dp[arr[0]] += 1;
	
	for(int i = 1; i < n; i++)
	{
		vector<int> curr(tar + 1,0);
		for(int j = 0; j <= tar; j++)
		{
			int take = 0;
			if(j - arr[i] >= 0) take = dp[j-arr[i]];
			int nottake = dp[j];
			curr[j] = (take + nottake);
		}
		dp = curr;
	}
	return dp[tar];
}

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << findWays(arr,k) << endl;
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