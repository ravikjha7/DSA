#include<bits/stdc++.h>
using namespace std;

struct Node {
    struct Node* left;
    int data;
    int height;
    struct Node* right;
};
struct Node* root = NULL;

int height(struct Node *p)
{
    int hl,hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node* p) {
    int hl,hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl-hr;
}

struct Node* LLRotation(struct Node* p) {
    struct Node* pl = p->left;
    struct Node* plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = height(p);
    pl->height = height(pl);

    if(root == p) root = pl;

    return pl;
}

struct Node* LRRotation(struct Node* p) {
    struct Node* pl = p->left;
    struct Node* plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);

    if(p == root) root = plr;

    return plr;
}

struct Node* RRRotation(struct Node* p) {
    struct Node* pl = p->right;
    struct Node* plr = pl->left;
    pl->left = p;
    p->right = plr;
    p->height = height(p);
    pl->height = height(pl);

    if(root == p) root = pl;

    return pl;
}

struct Node* RLRotation(struct Node* p) {
    struct Node* pl = p->right;
    struct Node* plr = pl->left;
    pl->left = plr->right;
    p->right = plr->left;
    plr->right = pl;
    plr->left = p;
    pl->height = height(pl);
    p->height = height(p);
    plr->height = height(plr);

    if(p == root) root = plr;

    return plr;
}

struct Node* recursiveinsert(struct Node *p, int key)
{
    if (p == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->left = temp->right = NULL;
        temp->height = 1;
        temp->data = key;
        return temp;
    }
    if (p->data < key)
        p->right = recursiveinsert(p->right, key);
    else if (p->data > key)
        p->left = recursiveinsert(p->left, key);
    p->height = height(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) return LLRotation(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1) return LRRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1) return RRRotation(p);
    if(BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1) return RLRotation(p);

    return p;
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

void PreOrder(struct Node* p)
{
    if(p == NULL) return;
    cout << p->data << " ";
    PreOrder(p->left);
    PreOrder(p->right);
}

int main()
{
    root = recursiveinsert(root,30);
    recursiveinsert(root,20);
    recursiveinsert(root,40);
    recursiveinsert(root,50);
    recursiveinsert(root,10);
    recursiveinsert(root,5);
    recursiveinsert(root,15);
    recursiveinsert(root,25);
    recursiveinsert(root,28);
    recursiveinsert(root,4);
    // PreOrder(root);
    cout << root->data << endl;
    cout << endl;

    return 0;
}