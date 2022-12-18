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
	if(dp[i][capacity] != -1) return dp[i][capacity];
	int take = 0;
	if(capacity - weight[i] >= 0) take = val[i] + knapSack(i - 1,capacity - weight[i],weight,val,dp);
	int nottake = knapSack(i - 1,capacity,weight,val,dp);
	return dp[i][capacity] = max(take,nottake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight + 1,-1));
	return knapSack(n - 1,maxWeight,weight,value,dp);
}

void solve()
{
	ll n,c;
	cin >> n >> c;
	vector<int> weight(n);
	vector<int> val(n);
	for(ll i = 0; i < n; i++) cin >> weight[i];
	for(ll i = 0; i < n; i++) cin >> val[i];
	
	cout << knapsack(weight,val,n,c) << endl;
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