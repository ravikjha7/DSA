#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
const int size = 2;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct Mat{
	ll m[size][size];
	Mat() {
		memset(m,0,sizeof(m));
	}
	void identity()
	{
		for(ll i = 0; i < size; i++) m[i][i] = 1;
	}
	Mat operator * (Mat a)
	{
		Mat res;
		for(ll i = 0; i < size; i++)
		{
			for(ll j = 0; j < size; j++)
			{
				for(ll k = 0; k < size; k++)
				{
					res.m[i][j] += (m[i][k] * a.m[k][j]);
				}
			}
		}
		return res;
	}
};

// SEQ SPP SPP2 Fibosum

ll Fib(ll n)
{
	Mat ans;
	ans.identity();
	Mat T;
	T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;
	if(n <= 2) return 1;
	n -= 2;
	while(n > 0)
	{
		if(n & 1) ans = ans*T;
		T = T*T;
		n >>= 1;
	}
	return (ans.m[0][0] + ans.m[0][1]) % mod;
}
int32_t main()
{
	file();
	int n;
	cin >> n;
	cout << Fib(n) << endl;
	return 0;
}