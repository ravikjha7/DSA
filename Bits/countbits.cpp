#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Count no of set bits in a number

// Time Complexity : O(logn)

int countbits(int n)
{
    int ans = 0;
    while(n>0)
    {
        if(n&1!=0) ans++;
        n = n>>1;
    }
    return ans;
}
// Time Complexity : O(logn) or O(ans)
int countbitshack(int n)
{
    int ans=0;
    while(n>0)
    {
        n = (n&(n-1));
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<countbitshack(n)<<endl;

    return 0;
}