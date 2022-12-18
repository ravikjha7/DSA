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

bool mycomp(pair<ll,ll> p1,pair<ll,ll> p2)
{
	if(p1.first < p2.first) return true;
	else if(p1.first > p2.first) return false;
	else return p1.second < p2.second;
}

bool mycomp2(pair<ll,ll> p1,pair<ll,ll> p2)
{
	if(p1.second < p2.second) return true;
	else if(p1.second > p2.second) return false;
	else return p1.first < p2.first;
}

void solve()
{
	ll w,h,k;
	cin >> w >> h >> k;
	vector<pair<ll,ll>> v;
	for(ll i = 0; i < k; i++)
	{
		ll a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	if(k == 0) {
		cout << (w)*(h) << endl;
		return;
	}
	sort(v.begin(),v.end(),mycomp);
	ll maxm = 0;
	for(ll i = 0; i < k; i++)
	{
		if(i == 0) {
			maxm = max(maxm,v[i].first-1);
		}
		else {
			maxm = max(maxm,v[i].first-v[i-1].first-1);
		}
	}
	maxm = max(maxm,w-v[k-1].first);
	sort(v.begin(),v.end(),mycomp2);
	ll maxm2 = 0;
	for(ll i = 0; i < k; i++)
	{
		if(i == 0) {
			maxm2 = max(maxm2,v[i].second-1);
		}
		else {
			maxm2 = max(maxm2,v[i].second-v[i-1].second-1);
		}
	}
	maxm2 = max(maxm2,h-v[k-1].second);
	cout << maxm*maxm2 << endl;
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