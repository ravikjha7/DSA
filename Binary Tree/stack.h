#include<bits/stdc++.h>
// #include "queue.h"
using namespace std;
typedef long long int ll;

struct node2 {
    struct Node* data;
    node2 *link;
};
node2* top = NULL;

void push(struct Node* data)
{
    node2* temp = new node2();
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
        cout << "Stack UndeFlow" << endl;
        return;
    }

    node2* temp = top;
    top = top->link;
    delete temp;
}

struct Node* peek()
{
    if(top == NULL)
    {
        return NULL;
    }
    return top->data;
}

bool isEmpty()
{
    if(top == NULL) return true;
    return false;
}
