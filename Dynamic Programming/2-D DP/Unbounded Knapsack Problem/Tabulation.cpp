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

int knapSack(int i,int capacity,vector<int> &weight,vector<int> &val,vector<vector<int>> &dp)
{
	if(i < 0) {
		return 0;
	}
	if(capacity == 0) return 0;
	if(dp[i][capacity] != -1) return dp[i][capacity];
	int take = 0;
	if(capacity - weight[i] >= 0) take = val[i] + knapSack(i,capacity - weight[i],weight,val,dp);
	int nottake = knapSack(i - 1,capacity,weight,val,dp);
	// cout << take << " " << nottake << endl;
	return dp[i][capacity] = max(take,nottake);
}

int unboundedKnapsack(int n, int maxWeight, vector<int> value,vector<int> weight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight + 1,0));
	for(int i = 1; i <= maxWeight; i++) {
		if(i % weight[0] == 0) {
			dp[0][i] = (i/weight[0])*(value[0]);
		} else {
			dp[0][i] = dp[0][i-1];
		}
	}
	for(int i = 1; i < n; i++)
    {
    	for(int j = 0; j <= maxWeight; j++)
    	{
    		int take = 0;
    		if(j - weight[i] >= 0) take = value[i] + dp[i][j - weight[i]];
    		dp[i][j] = max(take,dp[i-1][j]);
    	}
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j <= maxWeight; j++)
    	{
    		cout << dp[i][j] << " ";
    	}
    	cout << endl;
    }
    return dp[n-1][maxWeight];
}

void solve()
{
	int n,c;
	cin >> n >> c;
	vector<int> weight(n);
	vector<int> val(n);
	for(ll i = 0; i < n; i++) cin >> val[i];
	for(ll i = 0; i < n; i++) cin >> weight[i];
	cout << unboundedKnapsack(n,c,val,weight) << endl;
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