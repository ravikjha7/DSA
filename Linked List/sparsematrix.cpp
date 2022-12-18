#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int col;
    int val;
    Node *link;
    Node(int col,int val)
    {
        this->col = col;
        this->val = val;
        link = NULL;
    }
};

void addatlast(Node* &root,int col,int val)
{
    Node *temp = new Node(col,val);
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

void add(Node* root1[],Node* root2[],Node* root3[],int m,int n)
{
    for(int i=0;i<n;i++) root3[i] = NULL;
    for(int i=0;i<m;i++)
    {
        Node *p = root1[i];
        Node *q = root2[i];
        if(p!=NULL && q!=NULL)
        {
            for(int j=0;j<n;j++)
            {
                if(p!=NULL && q!=NULL && p->col==j && q->col==j) 
                {
                    addatlast(root3[i],j,p->val+q->val);
                    p = p->link;
                    q = q->link;
                }
                else if(p!=NULL && p->col==j) 
                {
                    addatlast(root3[i],j,p->val);
                    p = p->link;
                }
                else if(q!=NULL && q->col==j) 
                {
                    addatlast(root3[i],j,q->val);
                    q = q->link;
                }
            }
        }
        else if(p!=NULL) root3[i] = root1[i];
        else if(q!=NULL) root3[i] = root2[i];
    }
}


void display(Node* arr[],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        Node *p = arr[i];
        for(int j=0;j<n;j++)
        {
            if(p!=NULL && p->col==j)
            {
                cout<<p->val<<" ";
                p = p->link;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n,num;
    cin>>n>>m>>num;
    Node* arr[m];
    for(int i=0;i<n;i++)
    {
        arr[i] = NULL;
    }
    while(num--)
    {
        int row,col,val;
        cin>>row>>col>>val;
        addatlast(arr[row],col,val);
    }
    display(arr,m,n);
    int n2,m2,num2;
    cin>>n2>>m2>>num2;
    Node* arr2[m2];
    for(int i=0;i<n2;i++)
    {
        arr2[i] = NULL;
    }
    while(num2--)
    {
        int row,col,val;
        cin>>row>>col>>val;
        addatlast(arr2[row],col,val);
    }
    display(arr2,m2,n2);
    Node* arr3[n];
    add(arr,arr2,arr3,m,n);
    cout<<"The Addtion : "<<endl;
    display(arr3,m,n);
    return 0;
}