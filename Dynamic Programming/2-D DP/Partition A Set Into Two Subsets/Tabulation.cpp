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

int minSubsetSumDifference(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<int>> dp(n, vector<int> (sum + 1,0));
	for(int i = 0; i <= sum; i++) dp[0][i] = abs(sum - (2*i));
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= sum; j++) {
			int take = INT_MAX;
			if(j - arr[i] >= 0) take = dp[i-1][j - arr[i]];
			int nottake = dp[i-1][j];
			dp[i][j] = min(take,nottake);
		}
	}
	return dp[n-1][sum];
}


void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << minSubsetSumDifference(arr,n) << endl;
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