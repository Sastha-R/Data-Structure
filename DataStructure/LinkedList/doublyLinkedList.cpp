#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next = NULL;
    node *prev = NULL;
};

class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }

    void insertAtEnd()
    {
        node *newnode = new node();
        node *temp = head;
        cout << "enter the value ";
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    void insertAtBegin()
    {
        node *temp = new node();
        cout << "enter the value";
        cin >> temp->data;
        temp->prev = NULL;
        temp->next = head;
        if (head != NULL)
            head->prev = temp;
        head = temp;
    }

    void insertAtPosition()
    {
        int p = 0;
        node *newnode = new node();
        node *temp = head;
        cout << "enter the position: ";
        cin >> p;
        cout << "enter the value: ";
        cin >> newnode->data;
        if (head == NULL)
        {
            newnode->prev = NULL;
            newnode->next = NULL;
            head = newnode;
            return;
        }
        if (p == 1)
        {
            newnode->prev = NULL;
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            return;
        }
        for (int i = 1; i < p - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }

    void deleteAtBegin()
    {
        if (head == NULL)
            return;
        node *temp = head;
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        node *temp = head;
        node *prevNode = NULL;
        while (temp->next != NULL)
        {
            prevNode = temp;
            temp = temp->next;
        }
        temp->prev = NULL;
        prevNode->next = NULL;
        cout << "deleted";
    }

    void deleteAtPosition()
    {

        if (head == NULL)
        {
            cout << "list is empty";
            return;
        }

        int p;
        cout << "enter the position: ";
        cin >> p;

        if (p == 1)
        {
            node *temp = head;
            head = head->next;

            if (head != NULL)
                head->prev = NULL;
            return;
        }

        node *temp = head;

        for (int i = 1; i < p; i++)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    void forwardTraversal()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void backwardTraversal()
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
};
int main()
{
    LinkedList obj;
    int c = 0;

    do
    {
        cout << "1.insertAtEnd" << endl
             << "2.insertAtBegin" << endl
             << "3.insertAtPosition" << endl
             << "4.deleteAtBegin" << endl
             << "5.deleteAtEnd" << endl
             << "6.deleteAtPosition" << endl
             << "7.forwardTraversal" << endl
             << "8.backwardTraversal" << endl;
        cout << "enter your choice:";
        cin >> c;
        switch (c)
        {
        case 1:
            obj.insertAtBegin();
            break;
        case 2:
            obj.insertAtEnd();
            break;
        case 3:
            obj.insertAtPosition();
            break;
        case 4:
            obj.deleteAtBegin();
            break;
        case 5:
            obj.deleteAtEnd();
            break;
        case 6:
            obj.deleteAtPosition();
            break;
        case 7:
            obj.forwardTraversal();
            break;
        case 8:
            obj.backwardTraversal();
            break;
        case 9:
            cout << "exited";
            break;
        default:
            cout << "enter an valid option";
            break;
        }
    } while (c != 9);
    return 0;
}
