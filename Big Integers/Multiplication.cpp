#include<bits/stdc++.h>
using namespace std;

int main() {
  string a;
  int b;
  cin >> a >> b;
  string ans = "";
  reverse(a.begin(),a.end());
  int carry = 0;
  for(int i = 0; i < a.size(); i++) {
    int temp = ((a[i] - '0') * b)  + carry;
    ans += to_string(temp%10);
    carry = temp/10;
  }
  string extra = to_string(carry);
  reverse(extra.begin(),extra.end());
  if(carry > 0) ans += extra;
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}