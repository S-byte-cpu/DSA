#include <iostream>
#include <stdlib.h>
using namespace std;
void Insertion_End_Doubly_LL(int);
int Deletion_End_Doubly_LL();
void Display();
struct node
{
    struct node *pre;
    int item;
    struct node *next;
};
#define struct node node
node *start = NULL;
int main()
{
    int choise, data;
    cout << "\nInsertion in the front of the circular linked list::\n\n";
    do
    {
        cout << "\nFor Insertion::press1\n";
        cout << "For deletion::press2\n";
        cout << "For Display::press3\n";
        cout << "For Exit The Program::press4\n";
        cout << "Enter Your Choise: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "Enter Your Data:: ";
            cin >> data;
            Insertion_End_Doubly_LL(data);
            break;
        case 2:
            Deletion_End_Doubly_LL();
            break;
        case 3:
            Display();
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "OOPS...... its wrong choice!!!!!!\n";
            break;
        }
    } while (choise != 4);
}
void Insertion_End_Doubly_LL(int data)
{
    node *p, *l;
    p = (node *)malloc(sizeof(node));
    p->item = data;
    if (start == NULL)
    {
        start = p;
        p->pre = NULL;
        p->next = NULL;
    }
    else
    {
        l = start;

        while (l->next != NULL)
        {
            l = l->next;
        }
        l->next = p;
        p->pre = l;
        p->next = NULL;
    }
}
int Deletion_End_Doubly_LL()
{
    node *s = NULL, *f = NULL;

    if (start == NULL)
    {
        cout << "Linked List is Empty ::\n";
        return 0;
    }
    else
    {
        if (start->next == NULL)
        {
            start = NULL;
        }
        else
        {
            f = start;
            while (f->next != NULL)
            {
                s = f;
                f = f->next;
            }
            f->pre = NULL;
            s->next = NULL;
        }
        free(f);
    }
}
void Display()
{
    int choise;
    node *c, *b;
    if (start == NULL)
    {
        cout << "\nNo any Element's are Here for display::\n";
    }
    else
    {
        do
        {
            cout << "\nFor Display in Forward Direction only : Press 1\n";
            cout << "For Display in Backward Direction only : Press 2\n";
            cout << "For Display in Both Direction only : Press 3\n";
            cout << "For Exit The Display : Press 4\n";
            cout << "Enter Choice: ";
            cin >> choise;
            switch (choise)
            {
            case 1:
                c = start;
                cout << "\nValues in Forward Direction::\n";
                while (c != NULL)
                {
                    cout << " " << c->item;
                    b = c;
                    c = c->next;
                }
                break;
            case 2:
                c = start;
                while (c != NULL)
                {
                    b = c;
                    c = c->next;
                }
                cout << "\nValues in Backward Direction::\n";
                while (b->pre != NULL)
                {
                    cout << " " << b->item;
                    b = b->pre;
                }
                cout << " " << b->item;
                break;
            case 3:
                c = start;
                cout << "\nValues in Forkward Direction::\n";
                while (c != NULL)
                {
                    cout << " " << c->item;
                    b = c;
                    c = c->next;
                }

                cout << "\nValues in Backward Direction::\n";
                while (b->pre != NULL)
                {
                    cout << " " << b->item;
                    b = b->pre;
                }
                cout << " " << b->item;
                break;
            case 4:
                return;
                break;
            default:
                cout << "!!!!!!Its Wrong Choice............";
                break;
            }
        } while (choise != 4);
    }
}
