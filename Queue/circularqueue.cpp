#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Queue{
    public :
    int size;
    int front;
    int rear;
    int data;
    int *arr;
    Queue(int size = 7)
    {
        this->size = size;
        front = rear = 0;
        arr = new int[size];
    }

    void enqueue(int x)
    {
        if(front == (rear + 1) % size)
        {
            cout << "Queue is Full!!! " << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    void dequeue()
    {
        if(front == rear)
        {
            cout << "Queue Khali Hai !!!" << endl;
            return;
        }
        front = (front+1) % size;
    }

    int first()
    {
        if(front == rear)
        {
            cout << "Queue Khali Hai !!!" << endl;
            return -1;
        }
        return arr[(front+1)%size];
    }
    int last()
    {
        if(front == rear)
        {
            cout << "Queue Khali Hai !!!" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display()
    {
        if(front == rear)
        {
            cout << "Queue Khali Hai !!!" << endl;
            return;
        }
        cout << "The Elements Of Queue Are : ";
        for(int i = (front + 1) % size; i != front ; i = (i+1)%size) cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Queue q(7);
    q.dequeue();
    q.enqueue(99);
    q.enqueue(8);
    q.enqueue(69);
    q.enqueue(17);
    q.enqueue(34);
    q.enqueue(7);
    cout << q.first() << endl;
    cout << q.last() << endl;
    q.enqueue(3);
    q.enqueue(1);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << q.first() << endl;
    cout << q.last() << endl;
    q.dequeue();
    return 0;
}