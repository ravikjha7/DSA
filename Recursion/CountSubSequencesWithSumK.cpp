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

int printAllSubSequences(int arr[],int i,int n,int k,int &sum)
{
	if(i == n) {
		if(sum == k)
		{
			return 1;
		}
		return 0;
	}

	sum += arr[i];
	int l = printAllSubSequences(arr,i+1,n,k,sum);
	sum -= arr[i];
	int r = printAllSubSequences(arr,i+1,n,k,sum);
	return l + r;
}

void solve()
{
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans;
	int sum = 0;
	cout << printAllSubSequences(arr,0,n,k,sum) << endl;
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