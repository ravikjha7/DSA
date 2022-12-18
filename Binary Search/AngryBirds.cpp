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

bool isPossible(int diff, int arr[], int b, int n) {
	int prev = arr[0];

	int curr = 1;
	for(int i = 1; i < n; i++) {
		if(arr[i] - prev >= diff) {
			curr++;
			prev = arr[i];
		}
	}

	return curr >= b;

}

int maximumDistance(int b, int n, int arr[]) {
	int low = 0, high = arr[n - 1] - arr[0];

	int ans = -1;

	while(low <= high) {

		int mid = low + (high - low) / 2;

		if(isPossible(mid, arr, b, n)) {
			ans = mid;
			low = mid + 1;
		} else high = mid - 1;

	}

	return ans;

}

void solve()
{
	int n, b;
	cin >> n >> b;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];

	cout << maximumDistance(b, n, arr) << endl;

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