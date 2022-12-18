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

void solve()
{
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
	ll maxm = 0,minm = INT_MAX;
	for(ll i = 0; i < n; i++) {
		maxm = max(maxm,arr[i]);
		minm = min(minm,arr[i]);
	}
	cout << maxm - minm << endl;
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