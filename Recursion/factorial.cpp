#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll factorial(int n)
{
    if(n>0)
    return n*factorial(n-1);
    return 1;
}

// Time Complexity : O(N)
// Spcae Complexity : O(N)

int factorial2(int n,int ans)
{
    if(n == 0) cout << ans << endl;
    else factorial2(n-1,ans*n);
}

int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    factorial2(n,1);

    return 0;
}