#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
};
struct Node *root = NULL;

void insert(Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (p->data == key)
            return;
        if (p->data < key)
            p = p->right;
        else if (p->data > key)
            p = p->left;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = key;
    if (q == NULL)
        root = temp;
    else if (q->data < key)
        q->right = temp;
    else
        q->left = temp;
}

int height(struct Node *p)
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

Node *recursiveinsert(Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->left = temp->right = NULL;
        temp->data = key;
        return temp;
    }
    if (p->data < key)
        p->right = recursiveinsert(p->right, key);
    else if (p->data > key)
        p->left = recursiveinsert(p->left, key);
    return p;
}

struct Node* InPre(struct Node* p)
{
    while(p != NULL && p->right != NULL) p = p->right;
    return p;
}

struct Node* InSuc(struct Node* p)
{
    while(p != NULL && p->left != NULL) p = p->left;
    return p;
}

struct Node* Delete(struct Node* p,int key)
{
    struct Node* q ;
    if(p == NULL) return NULL;
    if(p->left == NULL && p->right == NULL)
    {
        if(p == root) root = NULL;
        delete p;
        return NULL;
    }
    // cout << "I am here" << endl;
    if(p->data < key) p->right = Delete(p->right , key);
    else if(p->data > key) p->left = Delete(p->left , key);
    else {
        if(height(p->left) > height(p->right))
        {
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left,q->data);
        }
        else
        {
            q = InPre(p->right);
            p->data = q->data;
            p->right = Delete(p->right,q->data);
        }
    }
    // cout << "I am here 2" << endl;
    return p;
}

Node *search(int key)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        if (p->data < key)
            p = p->right;
        else if (p->data > key)
            p = p->left;
    }
    return NULL;
}

Node *recursivesearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    if (p->data < key)
        return recursivesearch(p->right, key);
    if (p->data > key)
        return recursivesearch(p->left, key);
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
    // insert(root,7);
    // insert(root,3);
    // insert(root,8);
    // insert(root,99);
    // insert(root,1);
    root = recursiveinsert(root, 7);
    recursiveinsert(root, 3);
    recursiveinsert(root, 8);
    recursiveinsert(root, 99);
    recursiveinsert(root, 1);
    Delete(root,1);
    // cout << root->data << " Wow" << endl;
    Inorder(root);
    cout << endl;
    Node *temp = search(18);
    if (temp == NULL)
        cout << "Element Not Found" << endl;
    else
        cout << "Element Found" << endl;
    temp = recursivesearch(root, 18);
    if (temp == NULL)
        cout << "Element Not Found" << endl;
    else
        cout << "Element Found" << endl;
    return 0;
}