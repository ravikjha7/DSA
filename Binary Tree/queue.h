#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};

class node{
    public :
    struct Node* data;
    node* link;
    node(struct Node* data)
    {
        this->data = data;
        link = NULL;
    }
};

class Queue{
    public :
    node* front;
    node* rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(struct Node* x)
    {
        node* temp = new node(x);
        if(temp == NULL)
        {
            cout << "Queue Is Full!!!" << endl;
            return;
        }
        if(front == NULL) front = rear = temp;
        else
        {
            rear->link = temp;
            rear = temp;
        }
    }
    struct Node* dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue Is Empty!!!" << endl;
            return NULL;
        }
        node* temp = front;
        struct Node* x = temp->data;
        front = front->link;
        delete temp;
        return x;
    }

    int isEmpty()
    {
        if(front == NULL)
        {
            return 1;
        }
        return 0;
    }

    void display()
    {
        if(front == NULL)
        {
            cout << "Queue Khali Aahe!!!" << endl;
            return;
        }
        node* p = front;
        while(p!=NULL)
        {
            cout << p->data << " ";
            p = p->link;
        }
        cout << endl;
    }
};