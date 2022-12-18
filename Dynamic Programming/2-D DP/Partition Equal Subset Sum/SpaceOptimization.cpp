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

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	if(sum % 2) return false;
	vector<int> dp((sum / 2) + 1,0);
	dp[0] = 1;
	vector<int> curr((sum / 2) + 1,0);
	curr[0] = 1;
	sum /= 2;
	if(arr[0] <= sum) dp[arr[0]] = 1;

	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			bool take = false;
			if(j - arr[i] >= 0) take = dp[j - arr[i]];
			bool nottake = dp[j];
			curr[j] = (take | nottake);
		}
		dp = curr;
	}
	return dp[sum];
}


void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << canPartition(arr,n) << endl;
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