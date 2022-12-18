#include<bits/stdc++.h>
using namespace std;

int uniquenumber(int arr[],int n) {
  int xorv = 0;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    xorv ^= arr[i];
  }
  return xorv;
}

pair<int,int> twouniquenumbers(int arr[],int n) {
  int xor1 = 0;
  for(int i = 0; i < n; i++) {
    xor1 ^= arr[i];
  }
  int count = 0;
  while(xor1 > 0) {
    if((xor1 & 1) != 0) break;
    count++;
    xor1 /= 2;
  }
  count = (1<<count);
  int xora = 0, xorb = 0;
  for(int i = 0; i < n; i++) {
    if((arr[i] & count) == 0) {
      xora ^= arr[i];
    }
    else {
      xorb ^= arr[i];
    }
    // cout << "Mai Yaha Hu" << endl;
  }
  return {xora,xorb};
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  // cout << uniquenumber(arr,n) << endl;
  pair<int,int> p = twouniquenumbers(arr, n);
  cout << p.first << " " << p.second << endl;
  return 0;
}