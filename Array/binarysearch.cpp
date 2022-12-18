#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int BinarySearch(int arr[],int key,int n)
{
    // Low points to the start of the array
    // High points to the end of the array
    int low = 0,high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // If middle element is equal to required element , just return the index of the middle one
        if(arr[mid]==key)
        return mid;
        // If middle element is greater than required element , then discard the right half of the array
        else if(arr[mid]>key)
        high = mid-1;
        // If middle element is lesser than required element , then discard the left half of the array
        else
        low = mid+1;
    }
    // If element is not found in the array , return -1
    return -1;
}

int main()
{
    int arr[] = {1,3,7,8,99};
    int key = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    // Printing the index of the required element in the array
    cout<<BinarySearch(arr,key,n)<<endl;
    return 0;
}

// Time Compelxity : O(logn)
// Space Complexity : O(1)