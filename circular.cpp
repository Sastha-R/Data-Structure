```cpp
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next = NULL;
};

class LinkedList {
    public:
        node* head;

        LinkedList() {
            head = NULL;
        }

        void insertAtEnd() {
            node *newnode = new node();
            cout << "enter the value: ";
            cin >> newnode->data;

            // Empty list
            if (head == NULL) {
                head = newnode;
                newnode->next = head;
                return;
            }

            node *temp = head;

            // Stop when temp reaches the last node
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
        }

        void insertAtBegin() {
            node *newnode = new node();

            cout << "enter the value: ";
            cin >> newnode->data;

            // Empty list
            if (head == NULL) {
                head = newnode;
                newnode->next = head;
                return;
            }

            node *temp = head;

            // Find last node
            while (temp->next != head) {
                temp = temp->next;
            }

            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }

        void insertAtPosition() {
            int p;
            cout << "enter the position: ";
            cin >> p;

            cout << "enter the value: ";
            node *newnode = new node();
            cin >> newnode->data;

            if (p == 1) {
                insertAtBegin();
                return;
            }

            if (head == NULL) {
                cout << "Invalid position";
                delete newnode;
                return;
            }

            node *temp = head;

            for (int i = 1; i < p - 1; i++) {
                temp = temp->next;

                if (temp == head) {
                    cout << "Invalid position";
                    delete newnode;
                    return;
                }
            }

            newnode->next = temp->next;
            temp->next = newnode;
        }

        void deleteAtBegin() {
            if (head == NULL)
                return;

            // Only one node
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            node *temp = head;
            node *last = head;

            // Find last node
            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            delete temp;
        }

        void deleteAtEnd() {
            if (head == NULL)
                return;

            // Only one node
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            node *temp = head;
            node *prev = NULL;

            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = head;

            delete temp;

            cout << "deleted";
        }

        void deleteAtPosition() {
            int p;
            cout << "enter the position: ";
            cin >> p;

            if (head == NULL)
                return;

            if (p == 1) {
                deleteAtBegin();
                return;
            }

            node *temp = head;
            node *prev = NULL;

            for (int i = 1; i < p; i++) {
                prev = temp;
                temp = temp->next;

                if (temp == head) {
                    cout << "Invalid position";
                    return;
                }
            }

            prev->next = temp->next;

            delete temp;
        }

        void display() {
            if (head == NULL)
                return;

            node *temp = head;

            do {
                cout << temp->data << endl;
                temp = temp->next;
            } while (temp != head);
        }
};

int main() {
    LinkedList obj;
    int c;

    do {
        cout << "1.insertAtEnd" << endl
             << "2.insertAtBegin" << endl
             << "3.deleteAtEnd" << endl
             << "4.deleteAtBegin" << endl
             << "5.deleteAtPosition" << endl
             << "6.insertAtPosition" << endl
             << "7.display" << endl
             << "8.exit" << endl;

        cout << "enter your choice: ";
        cin >> c;

        switch(c) {
            case 1:
                obj.insertAtEnd();
                break;

            case 2:
                obj.insertAtBegin();
                break;

            case 3:
                obj.deleteAtEnd();
                break;

            case 4:
                obj.deleteAtBegin();
                break;

            case 5:
                obj.deleteAtPosition();
                break;

            case 6:
                obj.insertAtPosition();
                break;

            case 7:
                obj.display();
                break;

            case 8:
                cout << "exited";
                break;

            default:
                cout << "Invalid choice";
        }

        cout << endl;

    } while(c != 8);

    return 0;
}