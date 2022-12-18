#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Time Complexity : O(logmin(a,b))
// Space Complexity : O(1)

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(a,a%b);
}

int gcd_iterative(int a, int b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm (int a, int b) 
{
    return a / gcd(a, b) * b;
}