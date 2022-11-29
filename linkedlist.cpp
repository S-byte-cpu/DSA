//insertion perform in linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
void insertion_linkedlist(int);
void display();
void deletion();
struct node
{
    int item;
    struct node *next;
};
struct node *top=NULL;

int main()
{
    insertion_linkedlist(20);
    insertion_linkedlist(30);
    insertion_linkedlist(40);
    insertion_linkedlist(50);
    insertion_linkedlist(60);
    insertion_linkedlist(70);
    insertion_linkedlist(80);
    insertion_linkedlist(90);
    insertion_linkedlist(500);
    display();
    deletion();
    deletion();
   
    cout<<"\nAfter the deletion : \n";
    display();


}
void insertion_linkedlist(int data)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
   
    if(top==NULL)
    {
        p->item=data;
        top=p;
        p->next=NULL;    
    }
    else
    {
        p->item=data;
        p->next=top;
        top=p;    
    }
        
}
void display()
{
    struct node *p;
    p=top;
    while (p!= NULL)
    {
        cout<<" "<<p->item;
        p = p->next;
    }
}
void deletion()
{
    struct node *Item,*p;
    Item=p;
    p=top;
    if(top==NULL)
    {
        cout<<"NO any element here for deletion :";
    }
    else
    {
        Item=p;
        top=p->next;
    }
    free(Item);
}


