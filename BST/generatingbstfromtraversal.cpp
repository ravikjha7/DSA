#include<bits/stdc++.h>
#include "stack.hpp"
using namespace std;
typedef long long int ll;

void generateTree(int arr[],int n)
{
    Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = arr[0];
    temp->left = temp->right = NULL;
    root = temp;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < temp->data)
        {
            Node* p = (struct Node*)malloc(sizeof(struct Node));
            p->data = arr[i];
            p->left = p->right = NULL;
            temp->left = p;
            push(temp);
            temp = p;
        }
        else
        {
            temp->left = NULL;
            Node* p = peek();
            if(p==NULL || (p!=NULL && p->data > arr[i]))
            {
                p = (struct Node*)malloc(sizeof(struct Node));
                p->data = arr[i];
                p->left = p->right = NULL;
                temp->right = p;
                temp = temp->right;
            }
            else
            {
                while(temp->data < arr[i] && !empty())
                {
                    temp->right = NULL;
                    temp = peek();
                    pop();
                }
                p = (struct Node*)malloc(sizeof(struct Node));
                p->data = arr[i];
                p->left = p->right = NULL;
                temp->right = p;
                temp = temp->right;
            }
        }
        cout << "I am generating till " << i << " element" << endl;
    }
}

void Inorder(Node *p)
{
    if (p == NULL)
        return;
    Inorder(p->left);
    cout << p->data << " ";
    Inorder(p->right);
    // cout << "I am here" << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    generateTree(arr,n);
    cout << "Elements Of Trees Are : ";
    Inorder(root);
    cout << endl;
    return 0;
}