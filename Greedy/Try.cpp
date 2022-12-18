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
	if(n % 2 != 0) {
		cout << "2" << endl;
		return;
	}
	for(ll i = 3; i <= n; i++)
	{
		if((i*(i-1)/2) <= n) {
			ll sum = n - (i*(i-1)/2);
			if(sum % i == 0) {
				cout << i << endl;
				return;
			}
		}
		else {
			cout << "-1" << endl;
			return;
		}
	}
	cout << "-1" << endl;
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