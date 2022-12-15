// insertion and deletion in Doubly Linked List in specific Position
#include <iostream>
#include <stdlib.h>
using namespace std;
void Insertion_Doubly_LL(int);
void insertion_specific_position(int);
void Deletion_specific_position();
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
        cout << "\nFor Insertion::press 1\n";
        cout << "Insertion In specific position ::press 2\n";
        cout << "For Deletion In Specific Position ::press 3\n";
        cout << "For Display ::press 4\n";
        cout << "For Exit The Program ::press 5\n";
        cout << "\nEnter Your Choise: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            cout << "Enter Your Data:: ";
            cin >> data;
            Insertion_Doubly_LL(data);
            break;
        case 2:
            cout << "Enter Your Data:: ";
            cin >> data;
            insertion_specific_position(data);
            break;
        case 3:
            Deletion_specific_position();
            break;
        case 4:
            Display();
            break;
        case 5:
            cout << "Thankyou  for use this program:: ";
            break;
        default:
            cout << "OOPS...... its wrong choice!!!!!!\n";
            break;
        }
    } while (choise != 5);
}

void Insertion_Doubly_LL(int data)
{
    node *p = NULL, *l = NULL;
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

void insertion_specific_position(int data)
{
    int i, num;
    node *p = NULL, *s = NULL, *f = NULL;
    p = (node *)malloc(sizeof(node));

    p->item = data;

    cout << "Enter Your position : ";
    cin >> num;

    if (num == 1)
    {
        start = p;
        p->pre = NULL;
        p->next = NULL;
    }
    else
    {
        f = start;
        for (i = 1; i <= num - 1; i++)
        {
            s = f;
            f = f->next;
            if (s->next == NULL && i == num - 1)
            {
                s->next = p;
                p->next = NULL;
                p->pre = s;
                return;
            }
            else
            {
                if (s->next == NULL)
                {

                    cout << "invalid Position ::";
                }
            }
        }
        p->next = s->next;
        s->next = p;
        f->pre = s->next;
        p->pre = s;
    }
}
void Deletion_specific_position()
{
    int i, num;
    node *s = NULL, *f = NULL;

    cout << "Enter Your position : ";
    cin >> num;

    if (num == 1)
    {
        f = start;
        start = f->next;
        start->pre = NULL;
        free(f);
    }
    else
    {
        f = start;
        for (i = 1; i <= num - 1; i++)
        {
            s = f;
            f = f->next;
            if (i == num - 1)
            {
                f->pre = NULL;
                s->next = NULL;
                free(f);
                return;
            }
            else
            {
                if (f->next == NULL)
                {

                    cout << "\ninvalid Position ::\n";
                    return;
                }
            }
        }
        s->next = f->next;
        f->next->pre = s;
    }
}

void Display()
{
    int choise;
    node *c, *b;
    if (start == NULL)
    {
        cout << "\nNo any Element's are Here for Display::\n";
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