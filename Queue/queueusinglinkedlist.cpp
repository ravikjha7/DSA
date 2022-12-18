#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    Node* link;
    Node(int data)
    {
        this->data = data;
        link = NULL;
    }
};

class Queue{
    public :
    Node* front;
    Node* rear;
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int x)
    {
        Node* temp = new Node(x);
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
    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue Is Empty!!!" << endl;
            return;
        }
        Node* temp = front;
        front = front->link;
        delete temp;
    }

    void display()
    {
        if(front == NULL)
        {
            cout << "Queue Khali Aahe!!!" << endl;
            return;
        }
        Node* p = front;
        while(p!=NULL)
        {
            cout << p->data << " ";
            p = p->link;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.dequeue();
    q.display();
    q.enqueue(99);
    q.enqueue(8);
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    
    return 0;
}