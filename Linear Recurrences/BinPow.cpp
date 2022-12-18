#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll binpow(int a,int b) {
  int ans = 1;
  while(b > 0)
  {
    if(b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

int main()
{
  cout << binpow(7,3) << endl;
}