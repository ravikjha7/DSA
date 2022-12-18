#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
#define n 1e8

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// Initialising an array upto size 10^8 + 1
vector<int> arr(n+1,0);

void solve()
{
	// A Vector For Storing Prime Numbers
	vector<ll> ans;

	// Marking All Numbers Divisible By 2 as 1
	for(ll i = 4; i <= n; i += 2) arr[i] = 1;

	ans.push_back(2);

	// A For Loop For Checking Prime Upto 10^8
	for(ll i = 3; i <= n; i += 2)
    {
    	int p = i;
    	if(arr[i] == 0)
    	{
    		// Inserting All Primes Into A Vector
    		ans.push_back(i);

    		// Marking All Elements Divisible By Current Prime As 1
    		for(ll j = i*i; j <= n; j = j + (2*p))
    		{
    			arr[j] =  1;
    		}
    	}
    }
    // Printing The 1st, 101st, 201st, 301st, ......
    for(ll i = 0; i < ans.size(); i += 100) {
    	cout << ans[i] << "\n";
    }
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