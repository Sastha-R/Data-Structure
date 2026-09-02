
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Queue {
public:
    Node *head;

    Queue() {
        head = NULL;
    }

    void insertAtEnd() {
        Node *newnode = new Node();
        Node *temp = head;

        cout << "Enter the value: ";
        cin >> newnode->data;

        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        }
        else {
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    void deleteAtBegin() {

        if (head == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = head;

        head = head->next;

        cout << "Deleted\n";
    }

    void display() {
        Node *temp = head;

        if (head == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void front() {

        if (head == NULL) {
            cout << "Queue is empty";
            return;
        }

        cout << "Front element: " << head->data;
    }

};

int main() {

    Queue q;
    int choice;

    do {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "5. Front element\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            q.insertAtEnd();
            break;

        case 2:
            q.deleteAtBegin();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exited\n";
            break;

        case 5:
            q.front();
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

