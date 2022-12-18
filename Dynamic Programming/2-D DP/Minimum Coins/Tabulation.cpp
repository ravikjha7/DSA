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

int minimumElements(vector<int> &num, int x)
{
	vector<vector<int>> dp(num.size(),vector<int> (x + 1,INT_MAX));
    int ans = 0;
    for(int i = 0; i < num.size(); i++) dp[i][0] = 0;
    for(int i = 0; i <= x; i++)
    {
    	if(i % num[0] == 0) {
    		dp[0][i] = (i/num[0]);
    	}
    }
    for(int i = 1; i < num.size(); i++)
    {
    	for(int j = 1; j <= x; j++)
    	{
    		int take = INT_MAX;
    		if(j - num[i] >= 0) take = 1 + dp[i][j - num[i]];
    		dp[i][j] = min(take,dp[i-1][j]);
    	}
    }
    return dp[num.size()-1][x];
}

void solve()
{
	int n,amount;
	cin >> n >> amount;
	vector<int> coins(n);
	for(int i = 0; i < n; i++) cin >> coins[i];
	cout << minimumElements(coins,amount) << endl;
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