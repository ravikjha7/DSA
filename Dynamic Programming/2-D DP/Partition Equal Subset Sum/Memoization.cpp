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

bool canpartition(int n,int sum,vector<int> &arr,vector<vector<int>> &dp)
{
	
	if(sum < 0) return false;
	if(sum == 0) return true;
	if(n == 0) return (arr[0] == sum);
	if(dp[n][sum] != -1) return dp[n][sum];
	bool take = canpartition(n - 1,sum - arr[n],arr,dp);
	bool nottake = canpartition(n - 1,sum,arr,dp);
	return dp[n][sum] = (take|nottake);
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	if(sum % 2) return false;
	vector<vector<int>> dp(n + 1, vector<int> ((sum / 2) + 1,-1));
	return canpartition(n - 1,sum/2,arr,dp);
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