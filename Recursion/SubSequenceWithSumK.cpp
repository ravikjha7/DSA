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

bool printAllSubSequences(int arr[],int i,int n,int k,int &sum,vector<int> &ans)
{
	if(i == n) {
		if(sum == k)
		{
			for(auto i : ans) {
				cout << i << " ";
			}
			cout << endl;
			return true;
		}
		return false;
	}

	ans.push_back(arr[i]);
	sum += arr[i];
	if(printAllSubSequences(arr,i+1,n,k,sum,ans)) return true;
	ans.pop_back();
	sum -= arr[i];
	if(printAllSubSequences(arr,i+1,n,k,sum,ans)) return true;
	return false;
}

void solve()
{
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans;
	int sum = 0;
	printAllSubSequences(arr,0,n,k,sum,ans);
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