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

int minimumelements(int i,vector<int> &num,int tar) {
	if(i < 0) {
		if(tar == 0) return 1;
		return 0;
	}
	if(tar < 0) return 0;
	int take = minimumelements(i,num,tar - num[i]);
	int nottake = minimumelements(i - 1,num,tar);
	return take + nottake;
}

int minimumElements(vector<int> &num, int x)
{
    return minimumelements(num.size() - 1,num,x);
}

void solve()
{
	int n,amount;
	cin >> n;
	vector<int> coins(n);
	for(int i = 0; i < n; i++) cin >> coins[i];
	cin >> amount;
	cout << minimumElements(coins,amount) << endl;
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