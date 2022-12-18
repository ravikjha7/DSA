#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Insertion Sort Algorithm
// Pick one element and put it in the left sorted array 
// Perform it for every element except for the first one
// because the first element is always sorted...
// Time Complexity : O(N^2)
// Space Complexity : O(1)
void InsertionSort(int arr[],int n)
{
    int key,pos;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        pos = i - 1;
        // Loop To Find Right Position to insert key element
        while(pos>=0 && arr[pos]>key)
        {
            arr[pos+1] = arr[pos];
            pos--;
        }
        arr[pos+1] = key;
    }
}

int main()
{
    int arr[] = {7,3,8,99,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr,n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}