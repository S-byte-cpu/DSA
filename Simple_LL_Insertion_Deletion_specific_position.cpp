// INSERTION AND DELETION IN SPECIFIC POSITION
#include <iostream>
#include <stdlib.h>
using namespace std;
void Insertion(int);
int Insert_specific_Position(int);
int Deletion_Specific_position();
void Display();
struct node
{
    int item;
    struct node *next;
};
struct node *top = NULL;

int main()
{
    int data, n, i, choice;
    do
    {
        cout << "\nFor Insertion Press 1: \n";
        cout << "Insertion For specific position Press 2: \n";
        cout << "Deletion For Specific position Press 3: \n";
        cout << "For Display Press 4: \n";
        cout << "For Exit 5: \n";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nHow many numbers are you insert: ";
            cin >> n;
            cout << "Insert The Number's : ";
            for (i = 1; i <= n; i++)
            {
                cin >> data;
                Insertion(data);
            }
            break;
        case 2:
            cout << "\nInsert In Specific Position : \n\n";
            cout << "Enter The Number For Insertion : ";
            cin >> data;
            Insert_specific_Position(data);
            break;
        case 3:
            cout << "Deletion in Specific Position: \n";
            Deletion_Specific_position();
            break;
        case 4:
            Display();
            break;
        case 5:
            cout << "\nThankyou For Visit This Program!!!\n";
            exit;
            break;
        default:
            cout << "\nOOPS!!!! its Wrong key Plz Press Valid Key:\n";
        }

    } while (choice != 5);
}
void Insertion(int data)
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

int Insert_specific_Position(int data)
{
    int pos, i;
    struct node *slow, *fast, *p;
    p = (struct node *)malloc(sizeof(struct node));
    fast = (struct node *)malloc(sizeof(struct node));
    fast = top;
    if (top == NULL)
    {
        cout << "\nIts a First Position of insertion: \n";
        fast->item = data;
        fast->next = NULL;
        top = fast;
    }
    else
    {
        slow = (struct node *)malloc(sizeof(struct node));

        cout << "\n\nWhere You Will Insert Your Number ? : ";
        cin >> pos;
        for (i = 0; i < pos - 1; i++)
        {
            slow = fast;
            fast = fast->next;
            if (slow == NULL)
            {
                cout << "\nInvalid Entry : \n";
                return 1;
            }
        }
        p->item = data;
        slow->next = p;
        p->next = fast;
    }
}

int Deletion_Specific_position()
{
    int pos, i;
    struct node *slow, *fast;
    fast = (struct node *)malloc(sizeof(struct node));
    fast = top;
    if (top == NULL)
    {
        cout << "\nNo any elements here for deletion :\n";
    }
    else
    {
        slow = (struct node *)malloc(sizeof(struct node));

        cout << "\n\nWhere You Will Delete Your Number ? : ";
        cin >> pos;
        for (i = 0; i < pos - 1; i++)
        {
            slow = fast;
            fast = fast->next;
            if (slow == NULL)
            {
                cout << "\nInvalid Entry : \n";
                return 1;
            }
        }

        slow->next = fast->next;
        free(fast);
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
    cout << "\n\n";
}
