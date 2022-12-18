#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Kadane's Algorithm
// Time Complexity : O(N)
// Space Complexity : O(1)
int KadaneAlgo(int arr[],int n)
{
    int largestsum = 0;
    int currsum = 0;
    for(int i=0;i<n;i++)
    {
        currsum = currsum + arr[i];
        largestsum = max(largestsum,currsum);
        // Whenever sum becomes less than 0 (i.e negative) , then make it 0 
        // It will look like you have count elements till now
        currsum = max(currsum,0);
    }
    return largestsum;
}

int main()
{
    int arr[] = {1,3,-8,6,8,-20,5,-10,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<KadaneAlgo(arr,n)<<endl;

    return 0;
}