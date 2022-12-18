#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n],arr2[m];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    int ans[m+n];
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(arr[i]<=arr2[j]) ans[k++] = arr[i++];
        else ans[k++] = arr2[j++];
    }
    while(i<n)
    {
        ans[k++] = arr[i++];
    }
    while(j<m)
    {
        ans[k++] = arr2[j++];
    }

    for(int i=0;i<m+n;i++) cout<<ans[i]<<" ";
    cout<<endl;

    return 0;
}