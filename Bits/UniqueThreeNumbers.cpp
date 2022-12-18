#include<bits/stdc++.h>
using namespace std;

int uniquenumber(int arr[],int n) {
  int ans = 0;
  int bits[32] = {0};
  int count = 0;
  for(int i = 0; i < n; i++) {
    // count = 0;
    // while(arr[i]>0) {
    //   bits[31] += arr[i]%2;
    //   arr[i] /= 2;
    //   count++;
    // }
    for(int j=0;j<32;j++) {
      int jth_bit = arr[i]&(1<<j);
      if(jth_bit) {
        bits[j]++;
      }
    }
  }
  // count = 0;
  // for(int i=0;i<32;i++) {
  //   ans += ((bits[i]%3)*pow(2,count));
  //   count++;
  // }
  for(int i=0;i<32;i++) {
    bits[i] = bits[i]%3;
    ans += (bits[i] * (1 << i));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  cout << uniquenumber(arr,n) << endl;
  return 0;
}