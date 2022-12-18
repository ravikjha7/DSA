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
	return (a / gcd(a,b)) * b;
}

ll ncr(ll n, ll r) {
	if(n == r || r == 0) return 1;
	r = min(r, n - r);
	ll ans = n;
	for(ll i = 1; i < r; i++) 
	{
		ans *= (ll)(n - i);
		ans /= i;
	}
	ans /= r;
	return ans;
}

void solve()
{
	ll n;
	cin >> n;
	ll ans = 0;
	for(ll i = 5; i <= 7; i++) {
		ll curr = ncr(n, i);
		// cout << curr << endl;
		ans += curr;
	}
	cout << ans << endl;
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