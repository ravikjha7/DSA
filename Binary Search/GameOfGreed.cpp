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

bool isPossible(int mid, int arr[], int k, int n) {
	
	int curr = 0;

	for(int i = 0; i < n; i++) {
		curr += arr[i];
		if(curr >= mid) {
			curr = 0;
			k--;
		}
	}

	return k <= 0;
}

void solve()
{
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	int pref[n] = {0};
	pref[0] = arr[0];
	for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i];

	int low = 0;
	int high = pref[n - 1];

	int ans = -1;

	while(low <= high) {
		
		int mid = low + (high - low) / 2;

		if(isPossible(mid, arr, k, n)) {
			ans = mid;
			low = mid + 1;
		} else high = mid - 1;

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