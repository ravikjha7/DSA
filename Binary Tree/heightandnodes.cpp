#include<bits/stdc++.h>
#include "queue.h"
#include "stack.h"
using namespace std;
typedef long long int ll;

Node *root = NULL;

void create()
{
    Queue q;
    int x;
    Node *p,*temp;
    cout << "Enter Root Value : " << endl;
    cin >> x;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter Data For Left Child Of : " << p->data << endl;
        cin >> x;
        if(x == -1) p->left = NULL;
        else
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->left = temp;
            q.enqueue(temp);
        }

        cout << "Enter Data For Right Child Of : "  << p->data << endl;
        cin >> x;
        if(x == -1) p->right = NULL;
        else
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->right = temp;
            q.enqueue(temp);
        }
    }
}

int count(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = count(p->left);
        y = count(p->right);
        return x+y+1;
    }
    return 0;
}

int count2(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = count2(p->left);
        y = count2(p->right);
        if(p->left&&p->right) return x+y+1;
        else return x+y;
    }
    return 0;
}

int height(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = height(p->left);
        y = height(p->right);
        if(x>y) return x+1;
        else return y+1;
    }
    return 0;
}

int sum(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x = sum(p->left);
        y = sum(p->right);
        return x+y+p->data;
    }
    return 0;
}


int main()
{
    create();
    cout << count(root) << endl;
    cout << count2(root) << endl;
    cout << height(root) << endl;
    cout << sum(root) << endl;
    return 0;
}