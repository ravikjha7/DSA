#include<bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  string ans;
  if(a.size() > b.size()) {
     string add = "";
     for(int i = 0; i < a.size()-b.size(); i++) {
       add += '0';
     }
     b = add + b;
  }
  else
  {
    string add = "";
     for(int i = 0; i < b.size()-a.size(); i++) {
       add += '0';
     }
     a = add + a;
  }
  // cout << a << " " << b << endl;
  int carry = 0;
  for(int i = a.size()-1; i > 0; i--) {
    int temp = a[i] -'0' + b[i] - '0' + carry;
    ans = to_string((temp%10)) + ans;
    carry = temp/10;
  }
  int temp = a[0] -'0' + b[0] - '0' + carry;
  ans = to_string(temp) + ans;
  cout << ans << endl;
  return 0;
}