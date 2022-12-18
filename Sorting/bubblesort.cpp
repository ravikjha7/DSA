#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Buuble Sort Algorithm
// Time Complexity : O(N^2)
// Space Complexity : O(1)
void BubbleSort(int arr[],int n)
{
    int flag = 1;
    for(int i=0;i<n;i++) // i stands for Number of times
    {
        flag = 0;
        for(int j=0;j<n-i-1;j++) // j for element to be checked
        {
            if(arr[j]>arr[j+1]) 
            {
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
        }
        // If not a single element will be swapped , it means the array is sorted and hence , we 
        // can stop sorting
        if(flag==0) break;
    }
}

int main()
{
    int arr[] = {7,8,3,99,-1,-17};
    int n = sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}