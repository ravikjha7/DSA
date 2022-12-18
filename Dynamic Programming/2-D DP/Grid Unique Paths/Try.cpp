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
	ll brr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
	for(ll i = 0; i < n; i++) cin >> brr[i];
	if(n == 1) {
		cout << "0" << endl;
		return;
	}
	ll i = 0,j = 0;
	ll ans = 0;
	for(ll i = 1; i < n; i++) {
		if(arr[i] < brr[i-1]) {
			ans += arr[i];
		} else {
			ans += brr[i-1];
		}
	}
	cout << ans << endl;
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