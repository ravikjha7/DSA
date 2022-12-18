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
Node *root2 = NULL;
Node *root3 = NULL;

void push(Node* &root,int data)
{
    Node *temp = new Node(data);
    temp->link = root;
    root = temp;
}

void recursivetraverse(Node* &p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" -> ";
        recursivetraverse(p->link);
    }
}

Node* mergelists(Node* &root1,Node* &root2)
{
    Node *p = root1;
    Node *q = root2;
    Node *r = NULL;
    Node *t;
    if(p==NULL) 
    {
        r=p;
        return r;
    }
    else if(q==NULL) 
    {
        r=q;
        return r;
    }
    else if(p->data<=q->data) 
    {
        r=p;
        t=p;
        p = p->link;
        t->link = NULL;
    }
    else 
    {
        t=q;
        r=q;
        q = q->link;
        t->link = NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            t->link = p;
            p = p->link;
            t = t->link;
            t->link = NULL;
        }
        else
        {
            t->link = q;
            q = q->link;
            t = t->link;
            t->link = NULL;
        }
    }
    if(p!=NULL) t->link = p;
    if(q!=NULL) t->link = q;
    return r;
}

int main()
{
    push(root,99);
    push(root,17);
    push(root,8);
    push(root,7);
    push(root,3);
    push(root,1);
    push(root2,73);
    push(root2,42);
    push(root2,25);
    push(root2,18);
    push(root2,13);
    push(root2,11);

    root3 = mergelists(root,root2);
    recursivetraverse(root3);
    cout<<"NULL"<<endl;

    return 0;
}