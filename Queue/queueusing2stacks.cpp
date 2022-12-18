#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Queue{
    public :
    stack<int> s1;
    stack<int> s2;
    void enqueue(int x)
    {
        s1.push(x);
    }
    void dequeue()
    {
        if(!s2.empty())
        {
            s2.pop();
        }
        else
        {
            if(s1.empty())
            {
                cout << "Queue Khaali Aahe" << endl;
                return;
            }
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int top()
    {
        if(!s2.empty())
        {
            return s2.top();
        }
        else
        {
            if(s1.empty())
            {
                cout << "Queue Khaali Aahe" << endl;
                return -1;
            }
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(34);
    q.enqueue(7);
    q.dequeue();
    q.enqueue(67);
    cout << q.top() << endl;
    q.enqueue(27);
    q.dequeue();
    cout << q.top() << endl;
    q.enqueue(71);
    q.dequeue();
    q.enqueue(78);
    cout << q.top() << endl;
    return 0;
}