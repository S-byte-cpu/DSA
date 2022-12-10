// insertion and Deletion in the Fornt of the Circular linked list...
#include <iostream>
#include <stdlib.h>
using namespace std;
int Display();
void Insertion_Doubly_LL(int);
void Deletion_Doubly_LinkedList();
struct node
{
    struct node *pre;
    int item;
    struct node *next;
};
#define struct node node;
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
        cout << "For Exit the Program::press4\n";
        cout << "Enter Your Choise: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "Enter Your Data:: ";
            cin >> data;
            Insertion_Doubly_LL(data);
            break;
        case 2:
            Deletion_Doubly_LinkedList();
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
void Insertion_Doubly_LL(int data)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->item = data;
    p->pre = NULL;
    if (start == NULL)
    {
        start = p;
        p->next = NULL;
    }
    else
    {
        p->next = start;
        start->pre = p;
        start = p;
    }
}
void Deletion_Doubly_LinkedList()
{
    node *p;
    p = start;
    if (start == NULL)
    {
        cout << "\nLinked List is Empty::\n";
    }
    else
    {
        if (start->next == NULL)
        {
            start = NULL;
        }
        else
        {
            start = start->next;
            start->pre = NULL;
        }
    }
    free(p);
}

int Display()
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
            cout << "For Exit : Press 4\n";
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
                return 0;
                break;
            default:
                cout << "!!!!!!Its Wrong Choice............";
                break;
            }
        } while (choise != 4);
    }
}