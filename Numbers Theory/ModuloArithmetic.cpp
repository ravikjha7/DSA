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

ll m = mod;

ll addm(ll a, ll b) {
	return (a + b) % m;
}

ll subm(ll a, ll b) {
	return ((a - b) % m + m) % m;
}

ll mulm(ll a,ll b) {
	return (a * b) % m;
}

ll powrm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = mulm(ans, a);
		b /= 2;
		a = mulm(a, a);
	}
	return ans;
}

ll inv(ll a) {
	return powrm(a, m - 2);
}

ll divm(ll a, ll b) {
	return mulm(a, inv(b));
}

ll N = 1e5;
ll fact[(int)1e5 + 1];
void factm() {
	fact[0] = 1;
	for(ll i = 1; i <= N; i++) {
		fact[i] = mulm(fact[i - 1], i);
	}
}

ll ncr(ll n, ll r) {
	return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
}

ll npr(ll n, ll r) {
	return mulm(fact[n], inv(fact[n - r]));
}

void solve()
{
	cout << addm(3, 5) << "\n";

	cout << subm(3, 5) << "\n";

	cout << mulm(324, 234) << "\n";

	cout << divm(56, 2) << "\n";

	factm();

	cout << fact[5] << "\n";

	cout << ncr(5, 2) << "\n";

	cout << ncr(5778, 123) << "\n";

	cout << npr(5778, 123) << "\n";
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