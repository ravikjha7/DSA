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

int upperBound(int ele, int arr[], int n) {

	int low = 0, high = n - 1;

	int ans = -1;

	while(low <= high) {

		int mid = low + (high - low) / 2;

		if(arr[mid] < ele) low = mid + 1;
		else if(arr[mid] > ele) high = mid - 1;
		else {
			ans = mid;
			low = mid + 1;
		}

	}

	return ans;
}

int lowerBound(int ele, int arr[], int n) {
	int low = 0, high = n - 1;

	int ans = -1;

	while(low <= high) {

		int mid = low + (high - low) / 2;

		if(arr[mid] < ele) low = mid + 1;
		else if(arr[mid] > ele) high = mid - 1;
		else {
			ans = mid;
			high = mid - 1;
		}

	}

	return ans;
}

int BinarySearch(int ele, int arr[], int n) {
	int low = lowerBound(ele, arr, n);
	int up = upperBound(ele, arr, n);

	return up - low + 1;
}

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int ele;
	cin >> ele;

	cout << BinarySearch(ele, arr, n) << endl;
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