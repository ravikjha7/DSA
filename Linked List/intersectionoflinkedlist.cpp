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
Node *root1 = NULL;
Node *root2 = NULL;

void addatbegin(Node* &root,int data)
{
    Node *temp = new Node(data);
    temp->link = root;
    root = temp;
}

Node* intersection(Node* &root1,Node* &root2)
{
    stack<Node*> stk1;
    stack<Node*> stk2;
    Node *p = root1;
    Node *q = root2;
    while(p!=NULL)
    {
        stk1.push(p);
        p = p->link;
    }
    while(q!=NULL)
    {
        stk2.push(q);
        q = q->link;
    }
    Node * r = NULL;
    while(!stk1.empty() && !stk2.empty() && stk1.top()->data==stk2.top()->data)
    {
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    return r;
}

void intersect()
{
    Node *p = root1;
    Node *q = root2;
    while(q->link!=NULL)
    {
        p=p->link;
        q=q->link;
    }
    q->link = p;
}

void traverse()
{
    Node *p = root1;
    cout<<"The Elements Of Linked List Are : ";
    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p = p->link;
    }
    cout<<"NULL"<<endl;
    p = root2;
    cout<<"The Elements Of Linked List Are : ";
    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p = p->link;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    addatbegin(root1,1);
    addatbegin(root1,4);
    addatbegin(root1,3);
    addatbegin(root1,7);
    addatbegin(root1,8);
    addatbegin(root1,99);
    addatbegin(root2,87);
    addatbegin(root2,43);
    addatbegin(root2,29);
    addatbegin(root2,66);
    intersect();
    traverse();
    Node* intpoint = intersection(root1,root2);
    if(intpoint!=NULL)
    {
        cout<<intpoint->data<<endl;
    }
    else
    {
        cout<<"No Intersection Found!!!!!!"<<endl;
    }
    return 0;
}