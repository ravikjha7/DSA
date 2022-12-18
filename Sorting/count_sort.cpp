#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Count Sort Algorithm
// Just count the frequency of each element of the given array in a new array of size of naxinun element of given array + 1
// This Algorithm only works when you have the range of the elements of the given array
// Time Complexity : O(N + Range)
// Space Complexity : O(max(arr))
void CountSort(int arr[],int n)
{
    int maxm = INT_MIN;
    // Finding The Maximum Element Here
    for(int i=0;i<n;i++) maxm = max(maxm,arr[i]);
    
    // Array of size maximum element + 1
    int count[maxm+1] = {0};
    // Counting The Frequency Of Each Element
    for(int i=0;i<n;i++) count[arr[i]]++;
    int j = 0;
    // Storing The Values Back In Original Array
    for(int i=0;i<maxm+1;i++)
    {
        while(count[i]!=0)
        {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }
}

int main()
{
    int arr[] = {7,3,8,99,1,7,17};
    int n = sizeof(arr)/sizeof(arr[0]);

    CountSort(arr,n);

    for(auto i : arr) cout<<i<<" ";
    cout<<endl;

    return 0;
}