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
	int prev2 = 0;
	int prev = abs(heights[1] - heights[0]);
    for(int i = 2; i < n; i++)
    {
    	int curr = min(prev + abs(heights[i] - heights[i-1]),prev2 + abs(heights[i] - heights[i-2]));
    	prev2 = prev;
    	prev = curr;
    }
    return prev;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> heights(n,0);
	// vector<int> dp(n,-1);
	for(int i = 0; i < n; i++) cin >> heights[i];
	cout << frogJump(n,heights) << endl;
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