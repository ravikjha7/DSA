#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fastexpo(ll a,ll b)
{
    ll ans = 1;
    while(b>0)
    {
        if((b&1)==1) ans *= a;
        a *= a;
        b = b>>1;
    }
    return ans;
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<fastexpo(a,b)<<endl;

    return 0;
}