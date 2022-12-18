#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int exp;
    int coeff;
    Node* link;

    Node(int coeff,int exp)
    {
        this->exp = exp;
        this->coeff = coeff;
        link = NULL;
    }
};
Node *root = NULL;

void addatlast(Node* &root,int coeff,int exp)
{
    Node *temp = new Node(coeff,exp);
    if(root==NULL)
    {
        root = temp;
        temp->link == NULL;
        return;
    }
    Node *p = root;
    while(p->link!=NULL) p=p->link;
    p->link = temp;
}

void read(Node* &root , int n)
{
    int exp , coeff;
    for(int i=0;i<n;i++)
    {
        cin>>coeff>>exp;
        addatlast(root,coeff,exp);
    }
}

void display(Node *root)
{
    Node *p = root;
    while(p->link!=NULL)
    {
        cout<<p->coeff<<"x^"<<p->exp<<" + ";
        p = p->link;
    }
    cout<<p->coeff<<"x^"<<p->exp;
    cout<<endl;
}

ll evaulate(Node *root,int x)
{
    Node *p = root;
    ll sum = 0;
    while(p!=NULL)
    {
        sum += ((p->coeff)*pow(x,p->exp));
        p = p->link;
    }
    return sum;
}

void add(Node* root,Node* root2,Node* &root3)
{
    Node *p = root;
    Node *q = root2;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp>q->exp)
        {
            addatlast(root3,p->coeff,p->exp);
            p = p->link;
        }
        else if(p->exp<q->exp)
        {
            addatlast(root3,q->coeff,q->exp);
            q = q->link;
        }
        else if(p->exp==q->exp)
        {
            addatlast(root3,p->coeff+q->coeff,p->exp);
            p = p->link;
            q = q->link;
        }
    }
    while(p!=NULL)
    {
        addatlast(root3,p->coeff,p->exp);
        p = p->link;
    }
    while(q!=NULL)
    {
        addatlast(root3,q->coeff,q->exp);
        q = q->link;
    }
}

int main()
{
    Node* root = NULL;
    int n;
    cin>>n;
    read(root,n);
    display(root);
    cout<<evaulate(root,1)<<endl;
    Node *root2 = NULL;
    int n2;
    cin>>n2;
    read(root2,n2);
    display(root2);
    cout<<evaulate(root2,1)<<endl;

    Node* root3 = NULL;
    add(root,root2,root3);
    display(root3);
    cout<<evaulate(root3,1)<<endl;

    return 0;
}