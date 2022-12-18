#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    ll sum2 = 0;
    

    // Single Missing Element 

    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    //     sum2 += arr[i];
    // }

    // for(int i=0;i<n-1;i++)
    // {
    //     if(arr[i+1]!=arr[i]+1) cout<<arr[i]+1<<endl;
    // }

    // ll sum = 0;
    // int m = arr[0];
    // int o = arr[n-1];
    // sum += o*(o+1)/2 - m*(m-1)/2;
    // cout<<sum-sum2<<endl;

    // int temp = arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     if(arr[i]-i!=temp)
    //     {
    //         cout<<i+temp;
    //         break;
    //     }
    // }

    // Multiple Missing Elements

    // Time Complexity : O(N)
    // Space Complexity : O(1)

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // int temp = arr[0];
    // for(int i=1;i<n;i++)
    // {
    //     while(arr[i]-i!=temp)
    //     {
    //         cout<<i+temp<<" ";
    //         temp++;
    //     }
    // }
    // cout<<endl;

    // Single Missing Element in an UnSorted Array
    // Time Complexity : O(N)
    // Space Compleity : O(MAX_ELEMENT)
    int maxm = 0;
    int minm = INT_MAX;
    for(int i=0;i<n;i++)
    {
        maxm = max(arr[i],maxm);
        minm = min(arr[i],minm);
    }
    int ans[maxm+1] = {0};
    for(int i=0;i<n;i++)
    {
        ans[arr[i]] = 1;
    }
    for(int i=minm;i<maxm;i++)
    {
        if(ans[i]==0) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}