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
// Space Complexity : O(target)

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<int> dp(k + 1,0);
	vector<int> curr(k + 1,0);
	curr[0] = 1;
	// Base Case
	// Agar Index 0 pe koi value bachi hai and that value 
	// Equals To arr[0] then Yes
	if(arr[0] <= k) dp[arr[0]] = 1;
	dp[0] = 1;
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			bool take = false;
			if(j - arr[i] >= 0) take = dp[j-arr[i]];
			bool nottake = dp[j];
			curr[j] = (take | nottake);
		}
		dp = curr;
	}
	return dp[k];
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