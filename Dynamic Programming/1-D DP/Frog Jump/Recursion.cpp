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

int frogJump(int n, vector<int> &heights)
{
    if(n == 0) return 0;

    int left = frogJump(n-1,heights) + abs(heights[n] - heights[n-1]);
    int right = INT_MAX;
    if(n > 1) right = frogJump(n-2,heights) + abs(heights[n] - heights[n-2]);
    return min(left,right);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> heights(n,0);
	for(int i = 0; i < n; i++) cin >> heights[i];
	cout << frogJump(n-1,heights) << endl;
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