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

int main()
{
	file();
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		vector<int> m(n,-1);
		ll arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		ll sum[n] = {0};
		sum[0] = arr[0];
		for(int i = 1; i < n; i++) sum[i] = sum[i-1] + arr[i];
		int a = 0,b = 0;
		for(int i = 0; i < n; i++)
		{
			int ans = sum[i] % n;
			if(m[ans] == -1)
			{
			    m[ans] = i+1;
			}
			else {
			    b = i+1;
			    a = m[ans];
			    break;
			}
			
		}
			cout << b-a << endl;
			for(int i = a+1; i <= b; i++)
			{
				cout << i << " ";
			}
			cout << endl;
		}
	return 0;

}