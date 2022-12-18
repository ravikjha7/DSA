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

bool subsetsumtok(int n,int target,vector<int> &arr) {
	if(target == 0) return true;
	if(n == 0) return (arr[0] == target);

	bool take = subsetsumtok(n - 1, target - arr[n],arr);
	bool nottake = subsetsumtok(n - 1,target,arr);
	return (take | nottake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return subsetsumtok(n - 1,k,arr);
}

void solve()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << subsetSumToK(n,k,arr) << endl;
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