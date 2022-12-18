#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// The Question is you have been given a number N and a number M you have to replace the bits of M into N from the position i to j

// Approach : Suppose N = 1110001010101
//                    M = 100
//                    i = 2 , j = 4
//  So answer will be N = 1110001010001
//  So , we will first clear the bits of N from i to j that can be done using the clearbitsinrange function after that we need to left shift m by i bits and then their OR will give us the answer

void replaceBits(ll &n,ll m,int i,int j)
{
    int mask = (-1<<(j+1));
    mask = (mask|(1<<i)-1);
    n = (n&mask);
    m = (m<<i);
    n = (n|m);
}

int main()
{
    ll n,m;
    int i,j;
    cin>>n>>m>>i>>j;
    replaceBits(n,m,i,j);
    cout<<n<<endl;
    return 0;
}
