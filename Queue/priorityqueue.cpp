#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    int priority;
};

class pri_queue{
    public :
    int size;
    Node* arr;
    int rear;
    pri_queue(int size)
    {
        this->size = size;
        arr = new Node[size];
        rear = -1;
    }
    void enqueue(int x,int p)
    {
        if(rear == size - 1)
        {
            cout << "Queue Is Full!!" << endl;
            return;
        }
        rear++;
        arr[rear].data = x;
        arr[rear].priority = p;
    }

    int top()
    {
        if(rear == -1)
        {
            cout << "Queue Is Empty!!!";
            return -1;
        }
        int minm = 0;
        for(int i = 0; i <= rear; i++)
        {
            if(arr[minm].priority > arr[i].priority)
            {
                minm = i;
            }
        }
        return minm;
    }

    void dequeue()
    {
        if(rear == -1)
        {
            cout << "Queue Is Empty!!!";
            return;
        }
        int minm = top();
        for(int i = minm; i < rear; i++)
        {
            arr[i].data = arr[i+1].data;
            arr[i].priority = arr[i+1].priority;
        }
        rear--;
    }
    void display()
    {
        if(rear == -1)
        {
            cout << "Queue Is Empty!!!";
            return;
        }
        for(int i = 0; i <= rear; i++)
        {
            cout << arr[i].data << " ";
        }
        cout << endl;
    }
};

int main()
{
    pri_queue q(7);
    q.enqueue(34,3);
    q.enqueue(5,2);
    q.enqueue(2,1);
    q.display();
    q.enqueue(43,3);
    q.enqueue(7,2);
    q.enqueue(3,1);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();

    return 0;
}