#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int sum(int n)
{
    if(n>0)
    return n + sum(n-1);
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int ans = sum(n);
    cout<<ans<<endl;

    return 0;
}