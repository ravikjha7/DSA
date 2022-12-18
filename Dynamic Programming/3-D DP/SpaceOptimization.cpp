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

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
	vector<vector<int>> dp(c,vector<int> (c,INT_MIN));
    for(int i = 0; i < c; i++)
    {
    	for(int j = 0; j < c; j++)
    	{
    		dp[i][j] = grid[r-1][i];
    		if(i != j) dp[i][j] += grid[r-1][j];
    	}
    }
    int curr ;
    int maxm = INT_MIN;
    for(int i = r - 2; i >= 0; i--)
    {
    	vector<vector<int>> dp2(c,vector<int> (c,INT_MIN));
    	for(int j1 = 0; j1 < c; j1++)
    	{
    		for(int j2 = 0; j2 < c; j2++)
    		{
    			maxm = INT_MIN;
    			for(int j = -1; j <= 1; j++)
    			{
    				for(int k = -1; k <= 1; k++)
    				{
    					if(j1 + j < 0 || j1 + j >= c || j2 + k < 0 || j2 + k >= c) continue;
    					curr = dp[j1+j][j2+k];
    					maxm = max(maxm,curr);
    				}
    			}
    			maxm += grid[i][j1];
    			if(j1 != j2) maxm += grid[i][j2];
    			dp2[j1][j2] = maxm;
    		}
    	}
    	dp = dp2;
    }
    return dp[0][c - 1];
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) cin >> v[i][j];
	}
	cout << maximumChocolates(n,m,v) << endl;
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