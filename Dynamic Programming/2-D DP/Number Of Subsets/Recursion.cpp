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

int findways(vector<int> &arr,int n,int sum,int tar) {
	if(n < 0) {
		if(sum == tar) {
			return 1;
		}
		return 0;
	}
	int take = findways(arr,n - 1,sum + arr[n],tar);
	int nottake = findways(arr,n - 1,sum,tar);
	return take + nottake;	
}

int findWays(vector<int> &arr,int tar) {
	int n = arr.size();
    return findways(arr,n - 1,0,tar);
}

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << findWays(arr,k) << endl;
}

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}