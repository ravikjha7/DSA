#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Check whether a number is power of 2 or not
bool powerof2(int n)
{
    return !(n&(n-1));
}

int main()
{
    int n;
    cin>>n;
    cout<<powerof2(n)<<endl;

    return 0;
}