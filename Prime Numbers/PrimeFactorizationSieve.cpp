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

int arr[100001] = {0};
void seive()
{
	int n = 100000;
	for(ll i = 2; i <= n; i++)
	{
		int p = i;
		if(arr[i] == 0)
		{
			arr[i] = i;
			for(ll j = i*i; j <= n; j = j + p)
			{
				arr[j] =  i;
			}
		}
	}
}

void solve()
{
	ll n;
	cin >> n;
	while(n > 1)
	{
		cout << arr[n] << " ";
		n /= arr[n];
	}
	cout << endl;
}

int main()
{
	file();
	seive();
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