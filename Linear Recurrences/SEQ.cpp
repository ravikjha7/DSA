#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int size;

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll k = 2;
struct Mat{
  ll m[10][10];
  Mat() {
    memset(m,0,sizeof(m));
  }
  void identity()
  {
    for(ll i = 0; i < size; i++) m[i][i] = 1;
  }
  Mat operator * (Mat a)
  {
    Mat res;
    for(ll i = 0; i < size; i++)
    {
      for(ll j = 0; j < size; j++)
      {
        for(ll k = 0; k < size; k++)
        {
          res.m[i][j] += (m[i][k] * a.m[k][j]);
        }
      }
    }
    return res;
  }
};

// SEQ SPP SPP2 Fibosum

ll Fib(ll arr[],ll crr[],ll n,ll k)
{
  Mat ans;
  ans.identity();
  Mat T;
  for(int i = 0; i < k; i++)
  {
    T.m[i][0] = arr[i];
  }
  if(n < k) return arr[n];
  n -= (k-1);
  while(n > 0)
  {
    if(n & 1) ans = ans*T;
    T = T*T;
    n >>= 1;
  }
  ll res = 0;
  for(int i = 0; i < k; i++)
  {
    res += ans.m[0][i];
  }
  return (ans.m[0][0] + ans.m[0][1]) % mod;
}
int32_t main()
{
  file();
  ll t;
  cin >> t;
  while(t-- > 0)
  {
    ll n;
    cin >> n;
    ll arr[n];
    ll crr[n];
    for(ll i = 0; i < n; i++) cin >> arr[i];
    for(ll i = 0; i < n; i++) cin >> crr[i];
    cin >> k;
    size = k;
    cout << Fib(arr,crr,n,k) << endl;
  }
  
  return 0;
}