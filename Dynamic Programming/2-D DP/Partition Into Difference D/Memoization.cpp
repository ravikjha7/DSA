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

int f(int i,int d,int sum,int curr,int &ans,vector<int> &arr,vector<vector<int>> &dp) {
	if(i < 0) {
		if(2*curr == sum - d) return 1;
		return 0;
	}
	if(dp[i][curr] != -1) return dp[i][curr];
	int take = (f(i - 1,d,sum,curr + arr[i],ans,arr,dp))%mod;
	int nottake = (f(i - 1,d,sum,curr,ans,arr,dp))%mod;
	return dp[i][curr] = (take + nottake)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
	int ans = 0,sum = 0,curr = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	if(sum - d < 0 || (sum - d) % 2 != 0) return 0;
	vector<vector<int>> dp(n,vector<int> (sum + 1,-1));
    return f(n - 1,d,sum,curr,ans,arr,dp);
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