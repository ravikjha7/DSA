#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// My Method
// ll power(int a,int b)
// {
//     if(b==0)
//     return 1;
//     return a*power(a,b-1);
// }

// ll factorial(int n)
// {
//     if(n>0)
//     return n*factorial(n-1);
//     return 1;
// }

// ll TaylorSeries(int x,int n)
// {
//     if(n==0) return 1;
//     return TaylorSeries(x,n-1) + (power(x,n)/factorial(n));
// }

double TaylorSeries(int x,int n)
{
    static double p = 1 , f = 1;
    if(n==0) return 1;
    double r = TaylorSeries(x,n-1);
    p = p*x;
    f = f*n;
    return r + (p/f);
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<TaylorSeries(x,n)<<endl;

    return 0;
}