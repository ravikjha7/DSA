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

long long int houseRobber(vector<int>& arr)
{
    int n = arr.size();
    int prev2 = arr[0];
	int prev = max(prev2,arr[1]);
	for(int i = 2; i < n-1; i++)
	{
		int curr = max(prev,prev2 + arr[i]);
		prev2 = prev;
		prev = curr;
	}
	// cout << prev << endl;
    int prev4 = arr[1];
    int prev3 = max(prev4,arr[2]);
    for(int i = 3; i < n; i++)
    {
        int curr = max(prev3,prev4 + arr[i]);
        prev4 = prev3;
        prev3 = curr;
    }
    // cout << prev3 << endl;
    return max(prev,prev3);
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << houseRobber(arr) << endl;
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