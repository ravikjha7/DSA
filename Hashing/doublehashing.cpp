#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h1(int data) {
    return data%10;
}

int h2(int data) {
    return (7 - (data%7));
}

int Hash(int i,int data) {
    return (h1(data)+(i*h2(data)))%10;
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
    int arr[7] = {5,25,15,35,95};
    for(int i = 0;i < 5; i++) {
        insert(hash,arr[i]);
    }
    for(int i = 0;i < 10; i++) {
        cout << hash[i] << " ";
    }
    cout << endl;
    if(search(hash,15)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    if(search(hash,45)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    if(search(hash,95)) cout << "Element Found" << endl;
    else cout << "Not Found!!!" << endl;
    return 0;
}
