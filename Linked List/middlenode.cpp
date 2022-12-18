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
Node *root = NULL;

void addatbegin(int data)
{
    Node *temp = new Node(data);
    temp->link = root;
    root = temp;
}

Node* middlenode()
{
    Node *p = root,*q=root;
    while(p!=NULL && p->link!=NULL)
    {
        q = q->link;
        p = p->link->link;
    }
    return q;
}

int main()
{
    addatbegin(99);
    addatbegin(8);
    addatbegin(3);
    addatbegin(1);
    addatbegin(7);
    Node *mid = middlenode();
    cout<<mid->data<<endl;
    return 0;
}