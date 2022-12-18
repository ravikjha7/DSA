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

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0)
    {
        if((b & 1) == 1) ans *= a;
        a *= a;
        b = b >> 1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a,ll b)
{
	ll ab = a / (ll)gcd(a, b);
	ab *= b;
	return ab;
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];
	set<ll> s;
	ll ans = 1;
	for(ll i = 0; i < n; i++) {
		s.insert(gcd(arr[i], k));
	}
	for(auto i : s) {
		ans *= i;
	}
	if(ans % k == 0) {
		cout << "Yes" << endl;
		return;
	}
	cout << "No" << endl;
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