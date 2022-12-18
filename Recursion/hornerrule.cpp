#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Recusrive Method For Horner's Rule
double TaylorSeries(int x,int n)
{
    static double s = 1;
    if(n==0) return s;

    s = 1+x*s/n;
    return TaylorSeries(x,n-1);
}

// Iterative Method For Horner's Rule
double TaylorSeries2(int x,int n)
{
    double s = 1;
    for(;n>0;n--)
    {
        s = 1+x*s/n;
    }
    return s;
}

int main()
{
    int x,n;
    cin>>x>>n;
    cout<<TaylorSeries(x,n)<<endl;
    cout<<TaylorSeries2(x,n)<<endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)