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

int minimumelements(int i,vector<int> &num,vector<int> &v,int tar,vector<vector<int>> dp) {
	if(i < 0) {
		if(tar == 0) {
			return v.size();
		}
		return 1e8;
	}
	if(tar < 0) return 1e8;
	if(dp[i][tar] != -1) return dp[i][tar];
	v.push_back(num[i]);
	int take = minimumelements(i,num,v,tar - num[i],dp);
	v.pop_back();
	int nottake = minimumelements(i - 1,num,v,tar,dp);
	return dp[i][tar] = min(take,nottake);
}

int minimumElements(vector<int> &num, int x)
{
	vector<int> dp(x + 1,1e8);
    int ans = 0;
    for(int i = 0; i <= x; i++) dp[0] = 0;
    for(int i = 0; i <= x; i++)
    {
    	if(i % num[0] == 0) {
    		dp[i] = (i/num[0]);
    	}
    }
    for(int i = 1; i < num.size(); i++)
    {
    	vector<int> curr(x + 1,1e8);
    	curr[0] = 0;
    	for(int j = 1; j <= x; j++)
    	{
    		int take = 1e8;
    		if(j - num[i] >= 0) take = 1 + curr[j - num[i]];
    		curr[j] = min(take,dp[j]);
    	}
    	dp = curr;
    }
    return dp[x] != 1e8 ? dp[x] : -1;
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