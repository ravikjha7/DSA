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

// Time Complexity : O(2^(m*n))
// Space Complexity : O(Path Length) => O(m-1+n-1)

int GridUniquePaths(int i,int j) {
	// If You Reach At End Of Row Or Column, You Can Move In A Direct Straight Path
	// So You Will Definitely Reach There
	if(i == 0 || j == 0) return 1;

	int left = GridUniquePaths(i-1,j);
	int up = GridUniquePaths(i,j-1);
	
	return left + up;
}

void solve()
{
	int n,m;
	cin >> n >> m;
	int count = 0;
	cout << GridUniquePaths(n-1,m-1) << endl;
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