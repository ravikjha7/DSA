#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void reversearray(int arr[], int low, int high)
{
    while (low <= high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftrotate(int arr[], int n, int k)
{
    reversearray(arr, 0, k - 1);
    reversearray(arr, k, n - 1);
    reversearray(arr, 0, n - 1);
}

void rightrotate(int arr[], int n, int k)
{
    reversearray(arr, n - k, n - 1);
    reversearray(arr, 0, n - k - 1);
    reversearray(arr, 0, n - 1);
}
int main()
{

    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // leftrotate(arr, n, k);
    rightrotate(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}