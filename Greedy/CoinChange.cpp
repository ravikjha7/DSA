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

void solve()
{
	int total;
	cin >> total;
	// Denominations
	int curr[] = {1,2,5,10,20,50,100,200,500,2000};
	int n = sizeof(curr)/sizeof(curr[0]);
	
	for(int i = n - 1; i >= 0; i--)
	{
		// Printing Currencies and Their Number Of Notes
		cout << curr[i] << " " << (int)total/curr[i] << endl;
		
		// Removing Added Notes
		total %= curr[i];
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