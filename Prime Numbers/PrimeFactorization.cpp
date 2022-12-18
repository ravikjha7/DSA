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

// Time Complexity : O(sqrt(N))
void FindPrime(ll n)
{
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			while(n % i == 0)
			{
				cout << i << " ";
				n /= i;
			}
		}
	}
	if(n != 1) cout << n;
	cout << endl;
}

void solve()
{
	ll n;
	cin >> n;
	int i = 2;
	// Brute Force
	// Time Complexity : O(N)
	// while(n > 1)
	// {
	// 	if(n % i == 0) {
	// 		cout << i << " ";
	// 		n /= i;
	// 	} else {
	// 		i++;
	// 	}
	// }
	// cout << endl;
	FindPrime(n);
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