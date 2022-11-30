// INSERTION AND DELETION IN THE END OF THE LINKES LIST
#include <iostream>
#include <stdlib.h>
using namespace std;
void Insertion_End(int data);
void Display();
void Deletion_End();
struct node
{
    int item;
    struct node *next;
};
struct node *top = NULL;

int main()
{
    cout << "\nInsertion in the end of the linked list:\n";
    Insertion_End(10);
    Insertion_End(20);
    Insertion_End(30);
    Insertion_End(40);
    Insertion_End(50);
    Insertion_End(60);
    Insertion_End(70);
    Insertion_End(80);
    Insertion_End(90);
    Insertion_End(100);

    Display();

    cout << "\nDeletion in the end of the linked list:\n";
    Deletion_End();
    Deletion_End();
    Deletion_End();
    Deletion_End();
    Deletion_End();

    Display();
}

void Insertion_End(int data)
{
    struct node *p, *temp;
    p = (struct node *)malloc(sizeof(struct node));
    p->item = data;
    p->next = NULL;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = NULL;
    }
}
void Deletion_End()
{
    struct node *pre, *post;
    if (top == NULL)
    {
        cout << "No any element  is here :";
    }
    post = top;
    if (post->next == NULL)
    {
        post = NULL;
    }
    else
    {
        while (post->next != NULL)
        {
            pre = post;
            post = post->next;
        }
        pre->next = NULL;
        free(post);
    }
}

void Display()
{
    struct node *n;
    n = top;
    while (n != NULL)
    {
        cout << n->item << " ";
        n = n->next;
    }
}
