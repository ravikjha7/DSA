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

// Fixed Starting Point
// Variable Ending Point

int maximumchocolates(int r,int c,int i1,int j1,int i2,int j2,vector<vector<int>> &grid)
{
	if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return INT_MIN;
	if(i1 == r - 1) 
	{
		if(j1 != j2)
		return grid[i1][j1] + grid[i1][j2];
		return grid[i1][j1];
	}

	int curr;
	int maxm = INT_MIN;
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(j1 + i < 0 || j1 + i >= c || j2 + j < 0 || j2 + j >= c) continue;
			curr = maximumchocolates(r,c,i1+1,j1+i,i2+1,j2+j,grid);
			if(j1 != j2) curr += grid[i1][j1] + grid[i1][j2];
			else curr += grid[i1][j1];
			maxm = max(maxm,curr);
			// cout << maxm << " ";
		}
		// cout << maxm << " ";
		// cout << endl;
	}
	// cout << endl;
	return maxm;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    return maximumchocolates(r,c,0,0,0,c-1,grid);
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