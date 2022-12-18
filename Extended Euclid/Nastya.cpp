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

ll gcd(ll a, ll b)
{
	if (b == 0)
	return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

// a/g = l/b
// g = b*a/l

// Ax + By = g
// l = ab/g
// lg = ab

void solve()
{
	ll l,r,x,y;
	cin >> l >> r >> x >> y;
	ll pro = (ll)x*y;
	ll ans = 0;
	ll m = (ll)sqrt(pro);
	for(ll i = l; i <= min(r,m); i++) {
		if(pro % i == 0) {
			if(gcd(i,pro/i) == x) ans += 2;
		}
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