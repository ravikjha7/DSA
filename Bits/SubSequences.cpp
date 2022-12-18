#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void printSubSequence(string s) {
  int n = s.size();
  n = pow(2,n);
  int count = 0;
  string ans = "";
  for(int i = 0; i < n; i++)
  {
    int temp = i;
    ans = "";
    count = 0;
    while(temp > 0) {
      if(temp%2) {
        ans += s[count];
      }
      temp /= 2;
      count++;
    }
    cout << ans << endl;
  }
}

int main() {
  string s;
  cin >> s;
  printSubSequence(s);
  return 0;
}