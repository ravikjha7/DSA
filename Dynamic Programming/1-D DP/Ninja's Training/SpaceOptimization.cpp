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

int ninjaTraining(int n, vector<vector<int>> &arr)
{
    int dp[4];
    dp[0] = max(arr[0][1],arr[0][2]);
    dp[1] = max(arr[0][0],arr[0][2]);
    dp[2] = max(arr[0][0],arr[0][1]);
    dp[3] = max(arr[0][0],max(arr[0][1],arr[0][2]));

    for(int i = 1; i < n; i++) {
    	int curr[4] = {0};
    	for(int j = 0; j < 4; j++)
    	{
    		for(int k = 0; k < 3; k++)
    		{
    			if(k != j) 
    			{
    				int points = arr[i][k] + dp[k];
    				curr[j] = max(curr[j],points);
    			}
    		}
    	}
    	dp[0] = curr[0];
    	dp[1] = curr[1];
    	dp[2] = curr[2];
    	dp[3] = curr[3];
    }
    // cout << dp[n-1][0] << " " << dp[n-1][1] << " " << dp[n-1][2] << endl;
    return dp[3];
}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for(int i = 0; i < n; i++)
	{
		vector<int> temp;
		for(int j = 0; j < 3; j++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}
		v.push_back(temp);
	}
	cout << ninjaTraining(n,v) << endl;
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