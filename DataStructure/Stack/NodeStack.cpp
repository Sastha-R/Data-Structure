#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
public:
    Node *head;

    Stack() {
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

    void deleteAtEnd() {

        if (head == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        if (head->next == NULL) {
            head = NULL;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

        cout << "Deleted\n";
    }

    void display() {
        Node *temp = head;

        if (head == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void top(){
        Node *temp = head;

        if (head ==NULL)
        {
            cout<<"stack is empty";
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        cout<<temp->data;
    }

};

int main() {

    Stack s;
    int choice;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout<<"5.top element";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            s.insertAtEnd();
            break;

        case 2:
            s.deleteAtEnd();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exited\n";
            break;
        
        case 5:
            s.top();
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
