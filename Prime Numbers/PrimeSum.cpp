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

vector<ll> primesum(ll A) {
    ll arr[A + 1] = {0};
	for(ll i = 2; i <= A; i++)
	{
		ll p = i;
		if(arr[i] == 0)
		{
			arr[i] = 1;
			for(ll j = i*i; j <= A; j = j + p)
			{
				arr[j] =  2;
			}
		}
	}
    vector<ll> v;
    for(ll i = 2; i <= A; i++)
    {
        if(arr[i] == 1) {
            cout << i << " " << A-i << endl;
            if(arr[A-i] == 1) {
                v.push_back(i);
                v.push_back(A-i);
                return v;
            }
        }
    }
    return v;
}


void solve()
{
	ll n;
	cin >> n;
	vector<ll> ans = primesum(n);
	cout << ans[0] << " " << ans[1] << endl;
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