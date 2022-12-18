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

void push(int data)
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

void reverselist()
{
    Node *p = root;
    Node *q = NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p = p->link;
        q->link = r;
    }
    root = q;
}

void recursivereverselist(Node* p,Node* &q)
{
    if(p!=NULL)
    {
        recursivereverselist(p->link,p);
        p->link = q;
    }
    else root = q;
}

void makeLoop()
{
    Node *p = root;
    while(p->link!=NULL) p = p->link;
    p->link = root;
}

void isLoop()
{
    Node *fast = root;
    Node *slow = root;
    do{
        slow = slow->link;
        if(fast->link!=NULL) fast = fast->link;
        if(fast->link!=NULL) fast = fast->link;
    }while(fast&&slow && fast!=slow);
    if(fast==slow) cout<<"Loop Found!!!"<<endl;
    else cout<<"Loop Not Found!!!"<<endl;
}

int main()
{
    push(99);
    push(17);
    push(8);
    push(7);
    push(3);
    push(1);
    recursivetraverse(root);
    cout<<" NULL"<<endl;
    reverselist();
    recursivetraverse(root);
    cout<<" NULL"<<endl;
    Node *temp = NULL;
    recursivereverselist(root,temp);
    cout<<root->link->data<<endl;
    recursivetraverse(root);
    cout<<" NULL"<<endl;
    makeLoop();
    isLoop();
    return 0;
}