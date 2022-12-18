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

int minsubsetsumdifference(vector<int> &arr,int n,int sum,int total,vector<vector<int>> &dp)
{
	if(n == 0) {
		return abs(sum - total);
	}	
	if(dp[n][sum] != -1) return dp[n][sum];
	int take = minsubsetsumdifference(arr,n - 1,sum - arr[n],total + arr[n],dp);
	int nottake = minsubsetsumdifference(arr,n - 1,sum,total,dp);
	return dp[n][sum] = min(take,nottake);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<int>> dp(n,vector<int> (sum + 1,-1));
	return minsubsetsumdifference(arr,n - 1,sum,0,dp);
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