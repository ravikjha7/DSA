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
    if(root==NULL)
    {
        root = temp;
        temp->link = temp;
    }
    else
    {
        temp->link = root;
        Node *p = root;
        do{
            p = p->link;
        }while(p->link!=root);
        p->link = temp;
        root = temp;
    }
}

void deletefirstnode()
{
    if(root==NULL)
    {
        cout<<"Kaha Kaha se Aa Jaate Hai , Idhar Log"<<endl;
        return;
    }
    Node *p = root;
    while(p->link!=root)
    {
        p = p->link;
    }
    if(p==root)
    {
        delete root;
        root = NULL;
    }
    else
    {
        p->link = root->link;
        delete root;
        root = p->link;
    }
}

int length()
{
    if(root==NULL) return 0;
    int count=0;
    Node *p = root;
    do{
        p = p->link;
        count++;
    }while(p!=root);
    return count;
}

void addatafter(int data,int loc)
{
    if(loc==1)
    {
        addatbegin(data);
        return;
    }
    if(loc>length()+1)
    {
        cout<<"Kaha Kaha se Aa Jaate Hai , Idhar Log"<<endl;
        return;
    }
    Node *temp = new Node(data);
    Node *p = root;
    while(loc>2)
    {
        p = p->link;
        loc--;
    }
    temp->link = p->link;
    p->link = temp;
}

void traverse()
{
    if(root==NULL) return;
    Node *p = root;
    do{
        cout<<p->data<<" -> ";
        p = p->link;
    }while(p!=root);
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
        cout<<"Kaha Kaha se Aa Jaate Hai , Idhar Log"<<endl;
        return;
    }
    Node *p = root;
    while(loc>2)
    {
        p = p->link;
        loc--;
    }
    Node *temp;
    temp = p->link;
    p->link = p->link->link;
    delete temp;
}

void recursivetraverse(Node* &p)
{
    static int flag = 0;
    if(p!=root || flag==0)
    {
        flag = 1;
        cout<<p->data<<" -> ";
        recursivetraverse(p->link);
    }
    flag = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    addatbegin(99);
    addatbegin(8);
    addatbegin(3);
    addatbegin(1);
    addatbegin(25);
    addatbegin(7);
    addatafter(45,1);
    addatafter(49,length()+1);
    addatafter(5,5);
    addatafter(98,3);
    addatafter(98,20);
    deletefirstnode();
    deletenode(2);
    deletenode(length());
    deletenode(length()+1);
    addatbegin(25);
    deletenode(1);
    traverse();
    cout<<endl;
    recursivetraverse(root);
    cout<<endl;
    return 0;
}