#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};

struct node {
    struct Node* data;
    node *link;
};

node* top = NULL;
struct Node *root = NULL;

void push(struct Node* data)
{
    node* temp = new node();
    if(temp==NULL)
    {
        cout<<"Stack OverFlow!!!"<<endl;
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

void pop()
{
    if(top==NULL)
    {
        // cout << "Stack UndeFlow" << endl;
        return;
    }

    node* temp = top;
    top = top->link;
    delete temp;
}

struct Node* peek()
{
    if(top == NULL)
    {
        // cout << "Stack is Empty!!!" << endl;
        return NULL;
    }
    return top->data;
}

bool empty()
{
    if(top == NULL) return true;
    return false;
}