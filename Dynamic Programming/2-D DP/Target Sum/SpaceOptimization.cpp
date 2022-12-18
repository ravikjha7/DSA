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

int targetSum(int n, int target, vector<int>& arr) 
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	target = abs(target);
	if(target > sum) return 0;
	target = sum - target;
	vector<int> dp(target + 1,0);
	dp[0] = 1;
	if(2*arr[0] <= target) dp[2*arr[0]] += 1;
	for(int i = 1; i < n; i++) {
		vector<int> curr(target + 1,0);
		curr[0] = 1;
		for(int j = 0; j <= target; j++) {
			int take = 0;
			if(j - (2*arr[i]) >= 0) take = dp[j - (2*arr[i])];
			int nottake = dp[j];
			curr[j] = take + nottake;
		}
		dp = curr;
	} 
	return dp[target];
}


void solve()
{
	int n,target;
	cin >> n >> target;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << targetSum(n,target,arr) << endl;
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

