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

int unboundedKnapsack(int n, int maxWeight, vector<int> value,vector<int> weight) 
{
	vector<int> dp(maxWeight + 1,0);
	for(int i = weight[0]; i <= maxWeight; i++) {
		if(i % weight[0] == 0) {
			dp[i] = (i/weight[0])*(value[0]);
		} else {
			dp[i] = dp[i-1];
		}
	}
	for(int i = 1; i < n; i++)
    {
    	for(int j = 0; j <= maxWeight; j++)
    	{
    		int take = 0;
    		if(j - weight[i] >= 0) take = value[i] + dp[j - weight[i]];
    		dp[j] = max(take,dp[j]);
    	}
    }
        
    return dp[maxWeight];
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