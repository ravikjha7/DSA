#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    int maxm = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxm = max(maxm,arr[i]);
    }
    int k;
    cin>>k;
    // // This one is for unsorted array
    // int hashmap[maxm+1] = {0};
    // for(int i=0;i<n;i++)
    // {
    //     hashmap[arr[i]]++;
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     if(hashmap[k-arr[i]]!=0 && hashmap[arr[i]]!=0 && k-arr[i]<=maxm)
    //     {
    //         cout<<arr[i]<<" "<<k-arr[i]<<endl;
    //         hashmap[arr[i]]--;
    //         hashmap[k-arr[i]]--;
    //     }
    // }

    // This one is for Sorted Array
    // Two Pointer Approach

    int low =0,high =n-1;
    while(low<=high)
    {
        if(arr[low]+arr[high]==k)
        {
            cout<<arr[low]<<" "<<arr[high]<<endl;
            low++;
            high--;
        }
        else if(arr[low]+arr[high]>k) high--;
        else low++;
    }
    return 0;
}