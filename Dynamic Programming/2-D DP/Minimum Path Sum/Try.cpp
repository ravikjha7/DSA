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
	if(n == 1 || n == 3) {
		cout << "-1" << endl;
		return;
	}
	if(n % 2 != 0) {
		cout << "2 4 5 1 3 ";
		ll start = 7;
		while(start <= n)
		{
			cout << start << " " << start-1 << " ";
			start += 2;
		} 
		cout << endl;
		return;
	}
	if(n == 2) {
		cout << "2 1" << endl;
		return;
	}
	cout << n-1 << " " << n << " ";
	for(ll i = 1; i < n-1; i++) cout << i << " ";
	cout << endl;
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