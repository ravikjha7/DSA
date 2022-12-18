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
    			for(ll j = i*i; j <= n; j = j + p)
    			{
    				arr[j] =  1;
    			}
    		}
    	}
    }
     
    void solve()
    {
    	ll n,m;
    	cin >> m >> n;
    	ll ans[n-m+1] = {0};
    	ll count = 0;
    	vector<ll> v;
    	for(ll i = 2; i <= sqrt(n); i++)
    	{
    		if(arr[i] == 0)
    		{
    			v.push_back(i);
    			// cout << i << " ";
    		}
    	}
    	// cout << endl;
    	for(auto p : v)
    	{ 
    		if(p *p > n) {
    			break;
    		}
    		ll start = (m/p)*p;
    		if(p >= m && p <= n) {
    			start = 2*p;
    		}
    		for(ll j = start; j <= n; j += p)
    		{
    			if(j < m) continue;
    			// if(j == p) continue;
    			ans[j-m] = 1;
    		}
    	}
    	// cout << endl;
    	for(ll i = 0; i <= n-m; i++)
    	{
    		if(ans[i] == 0 && i+m != 1)
    		{
    			cout << i+m << endl;
    		}
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