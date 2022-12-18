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

// Time Complexity : O(logn)
int gcd(int a,int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void solve()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << endl;
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