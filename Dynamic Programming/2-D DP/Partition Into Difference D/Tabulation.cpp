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

int findWays(vector<int> &arr,int tar) {
	int n = arr.size(); 
	vector<vector<int>> dp(n,vector<int> (tar + 1,0));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
	if(arr[0] <= tar) dp[0][arr[0]] += 1;
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= tar; j++)
		{
			int take = 0;
			if(j - arr[i] >= 0) take = (dp[i-1][j-arr[i]])%mod;
			int nottake = (dp[i-1][j])%mod;
			dp[i][j] = (take + nottake)%mod;
		}
	}
	return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
	int ans = 0,sum = 0,curr = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	if(sum - d < 0 || (sum - d) % 2 != 0) return 0;
    return findWays(arr,(sum - d)/2);
}


void solve()
{
	int n,d;
	cin >> n >> d;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << countPartitions(n,d,arr) << endl;
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