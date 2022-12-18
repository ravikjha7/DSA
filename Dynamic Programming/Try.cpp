#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 998244353

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
	if(n == 1 && arr[0] == 1) {
		cout << "YES" << endl;
		return;
	}
	int count = 0;
	for(ll i = 0; i < n; i++)
	{
		if(arr[i] == 1) count++;
	}
	if(count != 1) {
		cout << "NO" << endl;
		return;
	}

	for(ll i = 0; i < n - 1; i++)
	{
		if(arr[i] < arr[i+1]) {
			ll diff = arr[i+1] - arr[i];
			if(diff != 1) {
				cout << "NO" << endl;
				return;
			}
		}
		if(arr[i] == n && arr[i+1] != 1) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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