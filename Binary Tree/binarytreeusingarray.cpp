#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

char tree[10];
void root(char key)
{
    if(tree[0]!='\0') cout << "Tree Already Exists!!" << endl;
    else tree[0] = key;
}

void set_left(char key , int parent)
{
    if(tree[parent]=='\0') cout << "Parent Does Not Exist!!" << endl;
    else tree[(parent*2)+1] = key;
}

void set_right(char key , int parent)
{
    if(tree[parent]=='\0') cout << "Parent Does Not Exist!!" << endl;
    else tree[(parent*2)+2] = key;
}

void print_tree()
{
    for(int i=0;i<10;i++)
    {
        if(tree[i]!='\0') cout << tree[i] << " ";
        else cout << "- ";
    }
    cout << endl;
}

int main()
{
    root('A');
    root('B');
    set_left('B',0);
    set_right('C',0);
    set_left('D',1);
    set_right('E',1);
    set_left('F',3);
    set_right('G',3);
    set_left('S',5);
    print_tree();
    return 0;
}