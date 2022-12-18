#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to sort two sorted parts of an array
void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int brr[high + 1];
    int k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            brr[k++] = arr[i++];
        else
            brr[k++] = arr[j++];
    }
    while (i <= mid)
        brr[k++] = arr[i++];
    while (j <= high)
        brr[k++] = arr[j++];
    for (int i = low; i <= high; i++)
        arr[i] = brr[i];
}

// Iterative Version Of Merge Sort
void iMergeSort(int arr[], int n)
{
    int p,i;
    for (p = 1; p <= n - 1; p = p * 2)
    {
        for (i = 0; i < n - 1; i += 2*p)
        {
            int high = min(i + 2*p - 1,n-1);
            int mid = min(i + p - 1,n-1);
            merge(arr, i, mid, high);
        }
    }
}

// Merge Sort Algorithm
// Divide and Conquer
// We will keep dividing the array smaller and smaller until we will get array of size 1
// then we will merge them
// Time Complexity : O(N^2)
// Space Complexity : O(N)
void mergeSort(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    if (low < high)
    {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArray(arr, n);
    // iMergeSort(arr, n);
    mergeSort(arr,0,n-1);
    printArray(arr, n);
    return 0;
}