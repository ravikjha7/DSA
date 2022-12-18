#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
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
	ll n;
	cin >> n;
	ull arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	if(n >= 130) 
	{
	    cout << "Yes" << endl;
	    return 0;
	}
	else {
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				for(int k = j+1; k < n; k++)
				{
				    for(int l = k + 1; l < n; l++)
				    {
				        if((arr[i]^arr[j]^arr[k]^arr[l]) == 0) {
				            cout << "Yes" << endl;
				            return 0;
				        }
				    }
				}
			}
		}
		cout << "No" << endl;
	}
	return 0;
}