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

int sum()
{
    int sum = 0;
    Node *p = root;
    while(p!=NULL)
    {
        sum += p->data;
        p = p->link;
    }
    return sum;
}

void maxm()
{
    if(root == NULL)
    {
        cout<<"Linked List is Empty!!!"<<endl;
        return;
    }
    int maxm = INT_MIN;
    Node *p = root;
    while(p!=NULL)
    {
        maxm = max(maxm,p->data);
        p = p->link;
    }
    cout<<"Maximum Element : "<<maxm<<endl;
}

void search(int key)
{
    if(root==NULL)
    {
        cout<<"Linked List is Empty!!!"<<endl;
        return;
    }
    Node *p = root;
    int index = 1;
    while(p!=NULL && p->data != key)
    {
        index++;
        p = p->link;
    }
    if(p==NULL) cout<<"Element is Not Present in Linked List"<<endl;
    else cout<<"Element Found At Index : "<<index<<endl;
}

void removeduplicates()
{
    if(root==NULL) return;
    Node *q=root;
    Node *p = q->link;
    while(p!=NULL)
    {
        if(p->data==q->data)
        {
            q->link = p->link;
            delete p;
            p = q->link;
        }
        else
        {
            q = p;
            p = p->link;
        }
    }
}

int recursivesearch(Node* &p,int key)
{
    static int index = 1;
    if(p==NULL) return -1;
    if(p->data == key) return index;
    index++;
    int ans = recursivesearch(p->link,key);
    return ans;
}

void insertinsorted(int data)
{
    Node *p = root;
    Node *temp = new Node(data);
    if(root==NULL || p->data>data)
    {
        temp->link = root;
        root = temp;
        return;
    }
    while(p->link!=NULL && p->link->data <= data) p = p->link;
    temp->link = p->link;
    p->link = temp;
}

int main()
{
    push(99);
    push(99);
    push(99);
    push(17);
    push(17);
    push(8);
    push(8);
    push(8);
    push(8);
    push(7);
    push(3);
    push(3);
    push(1);
    push(1);
    push(1);
    cout<<"The Elements Of The Linked List are : ";
    recursivetraverse(root);
    cout<<" NULL"<<endl;
    cout<<"The Sum of All Elements : "<<sum()<<endl;
    maxm();
    search(99);
    search(7);
    search(8);
    search(18);
    cout<<recursivesearch(root,-1)<<endl;
    insertinsorted(101);
    insertinsorted(0);
    insertinsorted(18);
    search(101);
    search(0);
    search(18);
    removeduplicates();
    cout<<"The Elements Of The Linked List are : ";
    recursivetraverse(root);
    cout<<" NULL"<<endl;
    return 0;
}