#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

ll binpow(ll a,ll b) {
  ll ans = 1;
  while(b > 0)
  {
    if(b & 1) 
    {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

int main()
{
  cout << binpow(7,300) << endl;
}