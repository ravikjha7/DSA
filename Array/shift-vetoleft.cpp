#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int low = 0,high = n-1;
    while(low<high)
    {
        if(arr[low]>=0 && arr[high]<0) swap(arr[low],arr[high]);
        if(arr[low]<0) low++;
        if(arr[high]>=0) high--;
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}