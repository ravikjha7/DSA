#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Prefix Sum Method
// Time Complexity : O(N^2)
// Space Complexity : O(N)
int LargestSubarraySum(int arr[],int n)
{
    int largestsum = 0;
    int prefixsum[n];
    prefixsum[0] = arr[0];

    for(int i=1;i<n;i++) prefixsum[i] = prefixsum[i-1] + arr[i];

    for(int i=0;i<n;i++)
    {
        int currentsum = 0;
        for(int j=i;j<n;j++)
        {
            if(i==0)
                currentsum = prefixsum[j];
            else
                currentsum = prefixsum[j] - prefixsum[i-1];

            largestsum = max(currentsum,largestsum);
        }
    }
    return largestsum;
}

int main()
{
    int arr[] = {1,3,-8,6,8,-20,5,-10,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LargestSubarraySum(arr,n)<<endl;

    return 0;
}