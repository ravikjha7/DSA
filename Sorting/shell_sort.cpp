#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Shell Sort Algorithm
// Similar To Insertion Sort
// Pick one element and put it in the left sorted array of gaps only
// gap value will be floored
// Perform it for every element except for the first one
// because the first element is always sorted...
// Time Complexity : O(NlogN)
// Space Complexity : O(1)
void shellSort(int arr[],int n)
{
    int key,pos;
    int gap = n/2;
    while(gap > 0) {
        for(int i=1;i<n;i++)
        {
            key = arr[i];
            pos = i - gap;
            // Loop To Find Right Position to insert key element
            while(pos>=0 && arr[pos]>key)
            {
                arr[pos+gap] = arr[pos];
                pos -= gap;
            }
            arr[pos+gap] = key;
        }
        gap /= 2;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n);
    shellSort(arr,n);
    printArray(arr, n);
    return 0;
}