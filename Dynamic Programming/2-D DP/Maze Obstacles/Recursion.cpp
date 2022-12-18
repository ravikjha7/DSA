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

int mazeobstacles(int i,int j,vector<vector<int>> &mat) {
	if(i >= 0 && j >= 0 && mat[i][j] == -1) return 0;
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;
	int left = mazeobstacles(i-1,j,mat);
	int up = mazeobstacles(i,j-1,mat);
	return left + up;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return mazeobstacles(n-1,m-1,mat);
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n);
	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < m; j++)
		{
			ll r;
			cin >> r;
			v[i].push_back(r);
		}
	}
	cout << mazeObstacles(n,m,v) << endl;
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