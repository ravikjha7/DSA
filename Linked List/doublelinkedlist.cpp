#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    Node *prev;
    Node *next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
Node *root = NULL;

void addatbegin(int data)
{
    Node *temp = new Node(data);
    temp->next = root;
    temp->prev = NULL;
    if(root!=NULL)
    root->prev = temp;
    root = temp;
}
int length()
{
    int count = 0;
    Node *p = root;
    while(p!=NULL) 
    {
        p = p->next;
        count++;
    }
    return count;
}

void reverse()
{
    struct Node *temp = NULL;
    struct Node *p = root;
    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if(p->prev==NULL)
        root = p;
        p = p->prev;
    }
}

void addatlocation(int data,int loc)
{
    if(loc==1)
    {
        addatbegin(data);
        return;
    }
    if(loc>length()+1)
    {
        cout<<"Kaha Kaha Se Aa Jaate Hai Idhar Log!!!"<<endl;
        return;
    }
    Node *temp = new Node(data);
    Node *p = root;
    while(loc>2)
    {
        p = p->next;
        loc--;
    }
    temp->prev = p;
    temp->next = p->next;
    if(p->next!=NULL)
    p->next->prev = temp;
    p->next = temp;
}

void deletefirstnode()
{
    if(root==NULL) return;
    Node *p = root;
    root = p->next;
    if(p->next!=NULL)
    p->next->prev = NULL;
    delete p;
}

void deletenode(int loc)
{
    if(root==NULL) return;
    if(loc==1)
    {
        deletefirstnode();
        return;
    }
    if(loc>length())
    {
        cout<<"Kaha Kaha Se Aa Jaate Hai , Idhar Log!!!"<<endl;
        return ;
    }
    Node *p = root;
    while(loc>2)
    {
        p = p->next;
        loc--;
    }
    Node *q = p->next;
    p->next = q->next;
    if(q->next!=NULL)
    q->next->prev = p;
    q->next = NULL;
    q->prev = NULL;
    delete q;
}

void traverse()
{
    Node *p = root;
    cout<<"NULL <-> ";
    while(p!=NULL)
    {
        cout<<p->data<<" <-> ";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    addatbegin(99);
    addatbegin(8);
    addatbegin(3);
    addatbegin(54);
    addatbegin(7);
    addatlocation(101,1);
    addatlocation(15,2);
    addatlocation(75,10);
    addatlocation(85,8);
    addatlocation(5,8);
    deletefirstnode();
    addatbegin(100);
    deletefirstnode();
    deletenode(1);
    deletenode(length());
    deletenode(length()+1);
    deletenode(5);
    deletenode(5);
    traverse();
    reverse();
    traverse();
    return 0;
}