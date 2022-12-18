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

// Results
// x = y1
// y = x1 - [A/B]*y1

vector<int> extendedGCD(int a,int b)
{
	// For The Base Case
	// X = 1, Y = 0 and GCD = a
	if(b == 0) {
		return {1,0,a};
	}
	vector<int> result = extendedGCD(b, a % b);
	int smallX = result[0];
	int smallY = result[1];
	int x = smallY;
	int y = smallX - (a/b)*smallY;
	return {x,y,result[2]};
}

void solve()
{
	int a,b;
	cin >> a >> b;
	vector<int> ans = extendedGCD(a,b);
	cout << ans[0] << " " << ans[1] << endl;
	cout << ans[2] << endl;
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
		solve();
	}
	return 0;
}