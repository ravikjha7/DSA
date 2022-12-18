#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node *link;
};
Node* top = NULL;

void push(int data)
{
    Node* temp = new Node();
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

    Node* temp = top;
    top = top->link;
    delete temp;
}

int peek()
{
    if(top == NULL)
    {
        cout << "Stack is Empty!!!" << endl;
        return -1;
    }
    return top->data;
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is Empty!!!" << endl;
        return;
    }
    Node* p = top;
    while(p!=NULL) 
    {
        cout << p->data << " ";
        p = p->link;
    }
    cout<<endl;
}

bool isEmpty()
{
    if(top == NULL) return true;
    return false;
}

bool isFull()
{
    Node* temp = new Node();
    if(temp == NULL) return true;
    return false;
}

int main()
{
    pop();
    push(99);
    push(8);
    push(7);
    push(3);
    display();
    cout << peek() <<endl;
    pop();
    display();
    cout << peek() <<endl;
    pop();
    pop();
    display();
    cout << peek() <<endl;
    pop();
    pop();
    display();
    cout << peek() <<endl;
    return 0;
}