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
	ll l,r;
	cin >> l >> r;
	ll arr[r+1];
	ll xor1 = 0;
	ll xor2 = 0;
	for(ll i = 0; i <= r; i++) 
	{
		cin >> arr[i];
		xor1 ^= arr[i];
		xor2 ^= i;
	}
	if(r % 2 == 0) {
		ll xor3 = xor1 ^ xor2;
		cout << xor3 << endl;
	}
	else {
		sort(arr,arr+r+1);
		cout << arr[r] << endl;
	}
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