#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Queue{
    public :
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int size = 7)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }

    void enqueue(int x)
    {
        if(rear == size - 1)
        {
            cout << "Queue Full Aahe!!" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
        cout << x << " pushed into queue!!!" << endl;
    }

    void dequeue()
    {
        if(front == rear)
        {
            cout << "Queue Khaali Aahe!!!" << endl;
            return;
        }
        front++;
    }

    bool isEmpty()
    {
        if(front == rear) return true;
        return false;
    }

    bool isFull()
    {
        if(rear == size - 1) return true;
        return false;
    }

    int first()
    {
        if(front!=rear) return arr[front+1];
        return -1;
    }

    int last()
    {
        if(rear != front) return arr[rear];
        return -1;
    }

    void display()
    {
        if(rear == front)
        {
            cout << "Queue Khali Hai!!" << endl;
            return;
        }
        cout << "Elements Of Queue Are : ";
        for(int i = front+1 ; i <= rear ; i++) cout << arr[i] << " ";
        cout<<endl;
    }
};

int main()
{
    int size;
    cin>>size;
    Queue q(size);
    q.dequeue();
    q.display();
    q.enqueue(99);
    q.enqueue(8);
    q.enqueue(3);
    q.enqueue(7);
    cout << q.first() << endl;
    cout << q.last() << endl;
    q.enqueue(17);
    q.enqueue(72);
    q.enqueue(71);
    q.enqueue(79);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(79);
    q.enqueue(5);
    q.display();

    cout << q.first() << endl;
    cout << q.last() << endl;

    return 0;
}