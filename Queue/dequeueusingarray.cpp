#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Dequeue{
    public :
    int size;
    int front;
    int rear;
    int *arr;
    Dequeue(int size = 7)
    {
        this->size = size;
        front = rear = -1;
        arr = new int[size];
    }
    void push_back(int x)
    {
        if(rear >= size - 1)
        {
            cout << "Can't insert at back!!!" << endl;
            return;
        }
        if(front == -1) front++;
        rear++;
        arr[rear] = x;
    }

    void push_front(int x)
    {
        if(front == 0)
        {
            cout << "Can't insert at front!!!" << endl;
            return;
        }
        if(front == -1)
        {
            front = 0;
            arr[++rear] = x;
            return;
        }
        arr[--front] = x;
    }

    void pop_front()
    {
        if(front == -1)
        {
            cout << "Can't pop from front!!!" << endl;
            return;
        }
        if(front == rear) front = rear = -1;
        else front++;
    }

    void pop_back()
    {
        if(front == -1)
        {
            cout << "Can't pop from back!!!" << endl;
            return;
        }
        if(front == rear) front = rear = -1;
        else rear--;
    }

    int top_front()
    {
        if(front == -1)
        {
            cout << "Saamne Kuchh Hai Hi Nahi!!!" << endl;
            return -1;
        }
        return arr[front];
    }

    int top_back()
    {
        if(front == -1)
        {
            cout << "Pichhe Kuchh Hai Hi Nahi!!!" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display()
    {
        if(front == -1)
        {
            cout << "Dequeue Khaali Aahe!!!" << endl;
            return;
        }

        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }

};

int main()
{
    Dequeue q(7);
    q.push_back(99);
    q.push_back(8);
    q.push_back(3);
    q.display();
    cout << q.top_back() << endl;
    cout << q.top_front() << endl;
    q.push_back(1);
    q.display();
    cout << q.top_back() << endl;
    q.push_back(3);
    q.push_front(13);
    q.push_front(35);
    q.display();
    q.push_front(33);
    q.display();
    q.push_front(32);
    q.push_back(31);
    cout << q.top_back() << endl;
    q.push_back(73);
    q.push_back(53);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.push_front(13);
    q.push_front(35);
    q.display();
    return 0;
}