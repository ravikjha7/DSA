#include <bits/stdc++.h>
using namespace std;

string addition(string a,string b) {
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
  return ans;
}

string subtract(string a,string b) {
	string ans = "";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int carry = 0;
	for(int i = 0; i < b.size(); i++) {
		if(a[i] - '0' < b[i] - '0' + carry) {
			ans += to_string(10 + a[i] - '0' - (b[i]-'0'+carry));
			carry = 1;
		}
		else {
			ans += to_string(a[i] - '0' - (b[i]-'0'+carry));
			carry = 0;
		}
	}
	for(int i = b.size(); i < a.size(); i++) {
		if(a[i] - '0' < carry) {
      if(a[i] - '0' - carry != 0 || i != a.size()-1)
			ans += to_string(10 + a[i] - '0' - carry);
			carry = 1;
		}
		else {
      if(a[i] - '0' - carry != 0 || i != a.size()-1)
			ans += to_string(a[i] - '0' - carry);
			carry = 0;
		}
	}
  reverse(ans.begin(),ans.end());
	return ans;
}

string divide(string s,int b) {
	int carry = 0;
  string ans = "";
	for(int i = 0; i < s.size(); i++) {
		ans += to_string(((10*carry)+s[i]-'0')/2);
		if((s[i]-'0')%2 == 0) carry = 0;
		else carry = 1;
	}
	return ans;
}

void solve(string a,string b) {
  	string c = subtract(a,b);
  // cout << c << endl;
	string d = divide(c,2);
  string f = "";
  int i = 0;
  while(d[i] == '0') i++;
  for(; i < d.size(); i++) {
    f += d[i];
  }
  string e = addition(f,b);
	cout << e << endl;
  cout << f << endl;
}

int main() {
	int t = 10;
  while(t--)
  {
    string a,b;
	  cin >> a >> b;
    solve(a,b);
  }
	return 0;
}