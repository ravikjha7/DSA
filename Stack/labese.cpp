#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    Node *link;
};
Node* top = NULL;

void push(int data)
{
    Node* temp = new Node();
    if(temp==NULL)
    {
        printf("Stack OverFlow!!\n");
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
    printf("%d pushed\n",data);
}

void display()
{
    if(top == NULL)
    {
        printf("Stack is Empty!!!\n");
        return;
    }
    Node* p = top;
    while(p!=NULL) 
    {
        printf("%d ",p->data);
        p = p->link;
    }
    printf("\n");
}

void myexit()
{
    printf("Thanks For Using The Program!!!");
    exit(1);
}


int main()
{
    int n;
    while(1)
    {
        printf("Enter Your Choice : \n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        scanf("%d",&n);
        
        switch (n)
        {
            case 1:
            printf("Enter Data To Insert : ");
            scanf("%d",&n);
            push(n);
            break;

            case 2 :
            printf("The Elements Of Stack Are : ");
            display();
            break;

            case 3 :
            myexit();
        }
    }
    return 0;
}