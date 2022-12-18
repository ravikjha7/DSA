#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Juggling Algorithm for rotating array , we can rotate both left side and right side
// In this algorithm , we will rotate elements in set rather than rotating them one by one
// No. of sets == __gcd(n,k)
// Time Complexity : O(N)
// Space Complexity : O(1)

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int g = __gcd(n,k);
    // for(int i=0;i<g;i++)
    // {
    //     int j = i;
    //     int temp = arr[i];
    //     while(1)
    //     {
    //         int d = (j+k)%n;
    //         if(d==i)
    //         {
    //             arr[j] = temp;
    //             break;
    //         }
    //         arr[j]=arr[d];
    //         j=d;
    //     }
    // }

    for(int i=n-1;i>n-g-1;i--)
    {
        int j = i;
        int temp = arr[i];
        while(1)
        {
            int d = (j+k)%n;
            if(d==i)
            {
                arr[j] = temp;
                break;
            }
            arr[j]=arr[d];
            j=d;
        }
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}