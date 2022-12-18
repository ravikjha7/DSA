#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll makeitbinary(ll n)
{
    ll ans = 0,power=1;
    while(n>0)
    {
        ans += (power*(n&1));
        power *= 10;
        n = n>>1;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    cout<<makeitbinary(n)<<endl;
    
    return 0;
}