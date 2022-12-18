#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int Hash(int i,int data) {
    return (data+(i*i))%10;
}

void insert(int hash[],int data) {
    int i = 0;
    while(hash[Hash(i,data)] != -1) i++;
    hash[Hash(i,data)] = data;
}

bool search(int hash[],int data) {
    int i = 0;
    while(i < 10) {
        if(hash[Hash(i,data)] == data) return true;
        i++;
    }
    return false;
}

int main()
{
    int hash[10];
    for(int i = 0; i < 10; i++) hash[i] = -1;
    int arr[7] = {7,49,94,44,45,86,1};
    for(int i = 0;i < 7; i++) {
        insert(hash,arr[i]);
    }
    for(int i = 0;i < 10; i++) {
        cout << hash[i] << " ";
    }
    cout << endl;
    if(search(hash,7)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    if(search(hash,44)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    if(search(hash,33)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    return 0;
}