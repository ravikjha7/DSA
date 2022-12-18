#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

bool palindrome(string s,int n,int i)
{
    if(i >= n/2) return true;
    if(s[i] == s[n-i-1]) return palindrome(s,n,i+1);
    return false;
}

int main()
{
    string s;
    cin >> s;
    if(palindrome(s,s.size(),0)) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
    return 0;
}