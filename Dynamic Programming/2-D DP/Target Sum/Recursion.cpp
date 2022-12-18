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

int targetsum(int i,int target,int sum,vector<int> &arr)
{
	if(i < 0) {
		if(target == sum) return 1;
		return 0;
	}
	if(target > sum) return 0;

	int take = targetsum(i - 1,target,sum - (2*arr[i]),arr);
	int nottake = targetsum(i - 1,target,sum,arr);
	// cout << take << " " << nottake << endl;
	return take + nottake;
}

int targetSum(int n, int target, vector<int>& arr) 
{
	int sum = 0;
	for(int i = 0; i < n; i++) sum += arr[i];
	return targetsum(n - 1,target,sum,arr);    
}


void solve()
{
	int n,target;
	cin >> n >> target;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << targetSum(n,target,arr) << endl;
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

