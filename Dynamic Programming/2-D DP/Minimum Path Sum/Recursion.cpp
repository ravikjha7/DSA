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

int minsumpath(vector<vector<int>> &grid,int i,int j)
{
	if(i == 0 && j == 0) {
		return grid[0][0];
	}
	if(i < 0 || j < 0) {
		return INT_MAX;
	}
	int up = minsumpath(grid,i-1,j);
	int left = minsumpath(grid,i,j-1);
	return min(up,left) + grid[i][j];
}

int minSumPath(vector<vector<int>> &grid) 
{
    return minsumpath(grid,grid.size()-1,grid[0].size()-1);
}

void solve()
{
	int n,m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int> (m));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	cout << minSumPath(v) << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}