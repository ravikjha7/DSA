#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printArray(int arr[],int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Quick Sort Algortihm
// Opposite Of Selection Sort
// Here , we will select an element and will find a place for it
// We will use the concept of Pivoted Index 
// Time Complexity : O(N^2)
// Space Complexity : O(1)

int partition(int arr[],int low,int high) {
    int i = low + 1;
    int j = high;
    // We are looking for an smaller element from the right side , and an larger element from the left side
    // If found we will swap them
    // Else we will swap the selected index and the element coming from the right side
    do {
        while(arr[i] <= arr[low] && i <= high) i++;
        while(arr[j] > arr[low] && j > low) j--;
        if(i < j) swap(arr[i],arr[j]);
    } while(i < j);
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(int arr[],int low,int high) {
    if(low < high) {
        int pivotedindex = partition(arr,low,high);
        quickSort(arr,low,pivotedindex-1);
        quickSort(arr,pivotedindex+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}