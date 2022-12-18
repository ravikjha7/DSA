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
	vector<ll> arr(n);
	ll minm = INT_MAX;
	for(ll i = 0; i < n; i++) cin >> arr[i];
	ll maxm = 0;
	set<ll> s;
	for(ll i = 0; i < n; i++) {
		maxm = max(arr[i],maxm);
		minm = min(arr[i],minm);
	}
	if(maxm == 0) {
		cout << "-1" << endl;
		return;
	}
	for(ll i = 0; i <= n; i++) {
		s.insert(i);
	}
	for(ll i = 0; i < n; i++)
	{
		s.erase(arr[i]);
	}
	auto it = s.begin();
	ll mex = *it;
	if(mex == 1) {
		cout << "-1" << endl;
		return;
	}
	if(mex == 0)
	{
		cout << minm - 1 << endl;
		return;
	}
	ll ans = 0;
	ll i = 0;
	while(i < n && arr[i] < mex) i++;
	if(i >= n) {
		cout << "0" << endl;
		return;
	}
	
	ll count = 1;
	for(ll j = i+1; j < n; j++)
	{
		if(arr[j] == arr[j-1] + 1) count++;
		else {
			if(count >= mex - 1) ans++;
			count = 1;
		}
	}
	if(count >= mex - 1 && arr[n-1] > mex) ans += 1;
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