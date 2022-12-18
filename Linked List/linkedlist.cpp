#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef long long int ll;

class Node{
    public :
    int data;
    Node *link;
    Node(int data)
    {
        this->data = data;
        link = NULL;  
    }
};
Node *root = NULL;

void addatbegin()
{
    int data;
    cout<<"Enter The Element You Want to Insert : ";
    cin>>data;
    Node *temp = new Node(data);
    temp->link = root;
    root = temp;
    cout<<data<<" Inserted at The Beginning"<<endl;
}

void addatend()
{
    int data;
    cout<<"Enter The Element You Want to Insert : ";
    cin>>data;
    Node *temp = new Node(data);
    if(root==NULL)
    {
        temp->link = root;
        root = temp;
    }
    else
    {
        Node *p = root;
        while(p->link!=NULL) p = p->link;
        p->link = temp;
    }
    cout<<data<<" Inserted At The End"<<endl;
}

int length()
{
    int count = 0;
    Node *p = root;
    while(p!=NULL) 
    {
        p = p->link;
        count++;
    }
    return count;
}

void addatafterlocation()
{
    int loc;
    cout<<"Enter Location To Insert Node : ";
    cin>>loc;
    if(loc>length()+1)
    {
        cout<<"You have entered a Location greater than the length of The Linked List"<<endl;
        return;
    }
    int data;
    cout<<"Enter The Element You Want to Insert : ";
    cin>>data;
    Node *temp = new Node(data);
    Node *p = root;
    if(loc==1)
    {
        temp->link = root;
        root = temp;
    }
    else if(loc==length()+1)
    {
        while(p->link!=NULL) p = p->link;
        p->link = temp;
    }
    else
    {
        while(loc>2)
        {
            p = p->link;
            loc--;
        }
        temp->link = p->link;
        p->link = temp;
    }
    cout<<data<<" Inserted at Position No. "<<loc<<endl;
}

void deletefirstnode()
{
    Node *p = root;
    Node *q;
    if(p->link==NULL)
    {
        cout<<"List can't be made Empty!!!"<<endl;
        return;
    }
    p->data = p->link->data;
    q = p->link;
    p->link = p->link->link;
    delete q;
    cout<<"First Node Deleted!"<<endl;
}

void deletelastnode()
{
    Node *p = root;
    Node *q;
    while(p->link!=NULL)
    {
        q = p;
        p = p->link;
    }
    q->link = NULL;
    cout<<"Last Node Deleted!"<<endl;
    delete p;
}

void deletenode()
{
    int data;
    cout<<"Enter The Data Of The Node to be deleted : ";
    cin>>data;
    Node *p = root;
    Node *q;
    if(p->data == data)
    {
        if(p->link==NULL)
        {
            cout<<"List can't be made Empty!!!"<<endl;
            return;
        }
        p->data = p->link->data;
        q = p->link;
        p->link = p->link->link;
        delete q;
        cout<<"Node with Value "<<data<<" Deleted!"<<endl;
        return;
    }
    while(p->data!=data)
    {
        q = p;
        p = p->link;
    }
    q->link = p->link;
    cout<<"Node with Value "<<data<<" Deleted!"<<endl;
    delete p;
}

void traverse()
{
    Node *p = root;
    cout<<"The Elements Of Linked List Are : ";
    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p = p->link;
    }
    cout<<"NULL"<<endl;
}

void myexit()
{
    cout<<"<------------- Thanks For Using Our Program -------------->"<<endl;
    cout<<"<----------- Follow Us For More Such Programs ------------->"<<endl;
    cout<<"Instagram : @thelunaticparadox"<<endl;
    cout<<"Twitter : @ParadoxLunatic"<<endl;
    cout<<"GitHub : @ravikjha7"<<endl;
    cout<<"LinkedIn : @ravikjha7"<<endl;
    getch();
    exit(1);
}

int main()
{
    int choice;
    menu :
    cout<<".........<Welcome To Our Program Of Linked List >........."<<endl;
    cout<<endl<<"Choose an Option From The Following :"<<endl;
    cout<<"1.Insert a Node"<<endl;
    cout<<"2.Delete a Node"<<endl;
    cout<<"3.Display Linked List"<<endl;
    cout<<"4.Length Of Linked List"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<endl<<"Enter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 :
            cout<<endl<<"1.Add At Beginning"<<endl;
            cout<<"2.Add At End"<<endl;
            cout<<"3. Add At Particular Location"<<endl;
            cout<<"Enter Your Choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1 :
                    addatbegin();
                    break;
                case 2 :
                    addatend();
                    break;
                case 3 :
                    addatafterlocation();
                    break;
                default :
                    cout<<"Kaha Kaha Se aa Jaate Hai Idhar Log!!!"<<endl;
            }
            break;
        case 2 :
            if(root==NULL)
            {
                cout<<"LinkedList is Empty"<<endl;
                break;
            }
            cout<<endl<<"1. Delete First Node"<<endl;
            cout<<"2. Delete Last Node"<<endl;
            cout<<"3. Delete a Node by Data"<<endl;
            cout<<"Enter Your Choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1 :
                    deletefirstnode();
                    break;
                case 2 :
                    deletelastnode();
                    break;
                case 3 :
                    deletenode();
                    break;
                default :
                    cout<<"Kaha Kaha Se aa Jaate Hai Idhar Log!!!"<<endl;
            }
            break;
        case 3 :
            traverse();
            break;
        case 4 :
            cout<<"Length Of The Linked List : "<<length()<<endl;
            break;
        case 5 :
            myexit();
            break;
        default :
            cout<<"Kaha Kaha Se aa Jaate Hai Idhar Log!!!"<<endl;
    }
    goto menu;
    return 0;
}