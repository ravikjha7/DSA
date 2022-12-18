#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// This method is actually taking O(2^n) times almost
ll Fibonacci(int n)
{
    if(n<=1)
    return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

// To reduce Time Complexity , we will use Memoization Technique i.e DP
// Means we will store all the seen values in an array
// i.e Reduce Time Complexity , Increase Space Complexity
// Time Complexity : O(N)
int fibb[200];

int Fibonacci3(int n)
{
    if(n<=1)
    {
        fibb[n] = n;
        return n;
    }
    if(fibb[n-2]==-1)
    fibb[n-2] = Fibonacci3(n-2);
    if(fibb[n-1]==-1)
    fibb[n-1] = Fibonacci3(n-1);
    fibb[n] = fibb[n-1] + fibb[n-2];
    return fibb[n-1] + fibb[n-2];
}

// Iterative Method
// Time Complexity : O(N)
// Space Complexity : O(1)
ll Fibonacci2(int n)
{
    int t0=0,t1=1;
    int s = 0;
    for(int i=2;i<=n;i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<200;i++)
    fibb[i] = -1;
    cout<<Fibonacci3(n)<<endl;

    return 0;
}