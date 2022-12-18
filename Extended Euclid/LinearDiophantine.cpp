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

// Linear Diopanthine Equations
// Polynomial Equation in two or more unknowns,
// such that only integral solution are required

// Problem Statement :
// Given 3 integers pf the form ax + by = c. Determine the equation has a solution such that x and y are both integral solutions.

void solve()
{
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> ans = extendedGCD(a,b);
	int g = ans[2];
	if(c % g != 0) {
		cout << "No Solution Found" << endl;
		return;
	}
	int k = c/g;
	cout << ans[0]*k << " " << ans[1]*k << endl;
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