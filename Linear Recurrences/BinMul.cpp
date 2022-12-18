#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 + 7;

ll binmul(ll a,ll b)
{
  int ans = 0;
  while(b > 0)
  {
    if(b & 1) 
    {
      ans += a;
      ans %= mod;
    }
    a += a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}

int main()
{
  ll a,b;
  cin >> a >> b;
  cout << binmul(a,b) << endl;
  return 0;
}