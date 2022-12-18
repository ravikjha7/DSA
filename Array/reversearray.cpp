#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Array is always Passed By Reference , so no need to return anything
void ReverseArray(int arr[],int n)
{
    // We will swap the first and last element , then second and second last element and so on until we will reach the middle element
    int start = 0, end = n-1;
    while(start<=end)
    {
        // swap is an inbuilt function in C++
        // You can also use
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    // Another Method :
    // for(int i=0;i<n/2;i++)
    // {
    //     swap(arr[i],arr[n-i-1]);
    // }
}

int main()
{
    int arr[] = {1,3,7,8,17,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    // Array is always passed as reference and hence no need to accept any value
    ReverseArray(arr,n);
    // Just Traversing Through The Array
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}

// Time Complexity : O(N/2) OR O(N)
// Space Complexity : O(1)