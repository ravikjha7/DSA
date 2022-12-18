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
    if(root==NULL)
    {
        root = temp;
        temp->prev = root;
        temp->next = root;
        return;
    }
    temp->prev = root->prev;
    temp->next = root;
    root->prev->next = temp;
    root->prev = temp;
    root = temp;
}

int length()
{
    if(root==NULL) return 0;
    int count=0;
    Node *p = root;
    do{
        p = p->next;
        count++;
    }while(p!=root);
    return count;
}

void addatlocation(int data , int loc)
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
    while(loc-->2) p = p->next;
    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;
}

void deletefirstnode()
{
    if(root==NULL) return;
    if(root->next==root) 
    {
        delete root;
        root = NULL;
    }
    Node *p = root;
    p->next->prev = root->prev;
    root->prev->next = p->next;
    root = p->next;
    delete p;
}

void deletenode(int loc)
{
    if(loc==1)
    {
        deletefirstnode();
        return;
    }
    if(loc>length())
    {
        cout<<"Kaha Kaha Se Aa Jaate Hai , Log Yaha!!!"<<endl;
        return;
    }
    Node *p = root;
    while(loc-->2) p=p->next;
    Node *q = p->next;
    p->next = q->next;
    q->next->prev = p;
    q->next = NULL;
    q->prev = NULL;
    delete q;
}

void traverse()
{
    Node *p = root;
    cout<<"NULL <-> ";
    if(root==NULL) return;
    do{
        cout<<p->data<<" <-> ";
        p = p->next;
    }while(p!=root);
    cout<<" NULL"<<endl;
}

int main()
{
    traverse();
    cout<<endl;
    addatbegin(99);
    addatbegin(8);
    addatbegin(3);
    addatbegin(54);
    addatbegin(7);
    traverse();
    addatlocation(17,1); 
    addatlocation(11,1); 
    addatlocation(69,length()+1); 
    addatlocation(143,length()); 
    addatlocation(100,length()+2); 
    addatlocation(10,4);
    traverse(); 
    deletefirstnode();
    deletenode(1);
    deletenode(length());
    deletenode(length());
    deletenode(4);
    deletenode(2);
    traverse();
    
    return 0;
}