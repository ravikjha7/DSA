#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int count=0;
    for(int i=0;i<n-1;i++)
    {
        count=1;
        if(arr[i+1]==arr[i])
        {
            while(arr[i]==arr[i+1] && i<n-1)
            {
                count++;
                i++;
            }
            cout<<arr[i]<<" "<<count<<endl;
        }
    }
    return 0;
}