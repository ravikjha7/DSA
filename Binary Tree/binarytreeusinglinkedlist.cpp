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

void Preorder(struct Node *p)
{
    while(p!=NULL || !isEmpty())
    {
        if(p!=NULL)
        {
            cout << p->data << " ";
            push(p);
            p = p->left;
        }
        else
        {
            p = peek();
            pop();
            p = p->right;
        }
    }
}

void PreOrder(struct Node* p)
{
    if(p == NULL) return;
    cout << p->data << " ";
    PreOrder(p->left);
    PreOrder(p->right);
}

void Inorder(struct Node *p)
{
    while(p!=NULL || !isEmpty())
    {
        if(p!=NULL)
        {
            push(p);
            p = p->left;
        }
        else
        {
            p = peek();
            pop();
            cout << p->data << " ";
            p = p->right;
        }
    }
}

void InOrder(struct Node* p)
{
    if(p == NULL) return;
    InOrder(p->left);
    cout << p->data << " ";
    InOrder(p->right);
}

void Postorder(struct Node *p)
{
    while(p!=NULL || !isEmpty())
    {
        if(p!=NULL)
        {
            if(p->right!=NULL) push(p->right);
            push(p);
            p = p->left;
        }
        else
        {
            p = peek();
            pop();
            if(p->right!=NULL && p->right==peek())
            {
                pop();
                push(p);
                p = p->right;
            }
            else
            {
                cout << p->data << " ";
                p = NULL;
            }
        }
    }
}

void PostOrder(struct Node* p)
{
    if(p == NULL) return;
    PostOrder(p->left);
    PostOrder(p->right);
    cout << p->data << " ";
}

void LevelOrder(struct Node* p)
{
    if(p==NULL) return;
    Queue q;
    cout << p->data << " ";
    q.enqueue(p);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        if(p->left!=NULL)
        {
            cout << p->left->data << " ";
            q.enqueue(p->left);
        }
        if(p->right!=NULL)
        {
            cout << p->right->data << " ";
            q.enqueue(p->right);
        }
    }
}

int main()
{
    create();
    cout << "Pre-Order : ";
    PreOrder(root);
    cout << endl;
    cout << "In-Order : ";
    InOrder(root);
    cout << endl;
    cout << "Post-Order : ";
    PostOrder(root);
    cout << endl;
    cout << "Pre-Order (Iterative) : ";
    Preorder(root);
    cout << endl;
    cout << "In-Order (Iterative) : ";
    Inorder(root);
    cout << endl;
    cout << "Post-Order (Iterative) : ";
    Postorder(root);
    cout << endl;
    cout << "Level-Order (Iterative) : ";
    LevelOrder(root);
    cout << endl;

    return 0;
}