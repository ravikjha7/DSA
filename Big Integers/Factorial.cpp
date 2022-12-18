#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

string multiply(string a,int b) {
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
  return ans;
}

string factorial(int n) {
  string ans = "1";
  for(int i = n; i >= 1; i--) {
    ans = multiply(ans,i);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  cout << factorial(n) << endl;
  return 0;
}