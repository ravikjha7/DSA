#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Selection Sort Algorithm
// Traverse From Beginning and mark every index as a position
// Find the minimum from rest of the array and swap it with element at currently marked position
// Time Complexity : O(N^2)
// Space Complexity : O(1)
void SelectionSort(int arr[],int n)
{
    int pos;
    for(int i=0;i<n-1;i++)
    {
        pos = i;
        int min = pos;
        // Finding the minimum element by traversing through rest of the array
        for(int j=pos;j<n;j++)
        {
            if(arr[j]<arr[min]) min = j;
        }
        // Swap the minimum element with the current one
        swap(arr[min],arr[pos]);
    }
}

int main()
{
    int arr[] = {7,3,8,99,1,17,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    SelectionSort(arr,n);

    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
    return 0;
}