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

ll binpow(ll a,ll b) {
  ll ans = 1;
  while(b > 0)
  {
    if(b & 1) 
    {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

ll sum(ll n)
{
	if(n < 10) return n;
	ll ans = 0;
	while(n > 0)
	{
		ans += (n%10);
		n /= 10;
	}
	return sum(ans);
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
		ll a,n;
		cin >> a >> n;
		ll ans = binpow(a,n);
		cout << sum(ans) << endl;
	}
	return 0;
}