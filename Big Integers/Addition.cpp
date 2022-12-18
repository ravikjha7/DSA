#include<bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  string ans = "";
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  if(a.size() > b.size()) swap(a,b);
  int carry = 0;
  for(int i = 0; i < a.size(); i++) {
    int temp = a[i] - '0' + b[i] - '0' + carry;
    ans += to_string(temp%10);
    carry = temp/10;
  }
  for(int i = a.size(); i < b.size() ; i++) {
    int temp = b[i] - '0' + carry;
    ans += to_string(temp%10);
    carry = temp/10;
  }
  if(carry > 0) ans += to_string(carry);
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}