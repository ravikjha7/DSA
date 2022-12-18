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

int GridUniquePaths(int n,int m) {
	vector<int> dp(m,1);
	for(int i = 1; i < n; i++)
	{
		vector<int> curr(m,0);
		curr[0] = 1;
		for(int j = 1; j < m; j++)
		{
			curr[j] = curr[j-1] + dp[j];
		}
		for(int j = 0; j < m; j++) {
			dp[j] = curr[j];
		}
	}
	return dp[m-1];
}

void solve()
{
	int n,m;
	cin >> n >> m;
	cout << GridUniquePaths(n,m) << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}













