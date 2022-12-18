#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    Node *link;
    Node(int data)
    {
        this->data = data;
        link = NULL;  
    }
};

int Hash(int data) {
    return data%10;
}

void insert(Node* hash[],int data) {
    int index = Hash(data);
    Node* temp = new Node(data);
    if(hash[index] == NULL) hash[index] = temp;
    else {
        Node* p = hash[index];
        while(p->link != NULL && p->link->data < data) p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
}

void pop(Node* hash[],int data) {
    int index = Hash(data);
    Node* p = hash[index];
    if(p == NULL) return;
    while(p->link != NULL && p->link->data < data) p = p->link;
    if(p->link != NULL && p->link->data == data) p->link = p->link->link;
}

Node* search(Node* hash[],int data) {
    int index = Hash(data);
    Node* p = hash[index];
    if(p == NULL) return NULL;
    while(p != NULL && p->data < data) p = p->link;
    if(p != NULL && p->data == data) return p;
    return NULL;
}

int main()
{
    int arr[10] = {7,3,8,1,99,17,27,25,42,83};
    Node* hash[10] = {NULL};
    for(int i = 0; i < 10; i++) insert(hash,arr[i]);
    for(int i = 0; i < 10; i++) {
        if(hash[i]!=NULL) {
            Node* p = hash[i];
            while(p!=NULL) {
                cout << p->data << " ";
                p = p->link;
            }
        }
    }
    cout << endl;
    pop(hash,27);
    pop(hash,33);
    for(int i = 0; i < 10; i++) {
        if(hash[i]!=NULL) {
            Node* p = hash[i];
            while(p!=NULL) {
                cout << p->data << " ";
                p = p->link;
            }
        }
    }
    cout << endl;
    Node* ans = search(hash,7);
    if(ans != NULL) cout << ans->data << endl;
    ans = search(hash,44);
    if(ans != NULL) cout << ans->data << endl;
    return 0;
}