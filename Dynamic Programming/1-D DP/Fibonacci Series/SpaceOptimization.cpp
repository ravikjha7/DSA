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

// Space Optimization : Bottom To Up Approach
// TC : O(N)
// SC : O(1)
void solve()
{
	int n;
	cin >> n;
	int prev = 1, prev2 = 0;
	// After Every Step
	// Previous will become Second Previous
	// And Current will become Previous
	for(int i = 2; i <= n; i++)
	{
		int curr = prev + prev2;
		prev2 = prev;
		prev = curr;
	}
	cout << prev << endl;
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