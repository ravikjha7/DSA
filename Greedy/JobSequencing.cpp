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

bool comp(pair<ll,ll> p1,pair<ll,ll> p2)
{
	return p1.second < p2.second;
}

void solve()
{
	int n;
	cin >> n;
	pair<ll,ll> arr[n];
	for(ll i = 0; i < n; i++)
	{
		ll a,b;
		cin >> a >> b;
		arr[i] = {a,b};
	}
	sort(arr,arr+n,comp);
	ll end = -1;
	ll count = 0;
	for(ll i = 0; i < n; i++)
	{
		if(arr[i].first >= end) {
			end = arr[i].second;
			count++;
		}
	}
	cout << count << endl;
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