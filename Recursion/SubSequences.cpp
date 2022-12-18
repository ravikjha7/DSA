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

void printAllSubSequences(int arr[],int i,int n,vector<int> &ans)
{
	if(i == n) {
		for(auto i : ans) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}

	ans.push_back(arr[i]);
	printAllSubSequences(arr,i+1,n,ans);
	ans.pop_back();
	printAllSubSequences(arr,i+1,n,ans);
}

void solve()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans;
	printAllSubSequences(arr,0,n,ans);
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