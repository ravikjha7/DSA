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
	multimap<ll,string> m;
	for(ll i = 0; i < n; i++)
	{
		string temp;
		ll no;
		cin >> temp >> no;
		m.insert({no,temp});
	}
	ll count = 1;
	ll ans = 0;
	for(auto i : m)
	{
		ans += abs(count - i.first);
		// cout << i.first << " ";
		count++;
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