// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node{
    int data;
    node *next = NULL;
};

class LinkedList{
    public:
        node* head;
        LinkedList(){
          head = NULL;
        }

        void insertAtEnd(){
            node *newnode = new node();
            node *temp = head;
            cout<<"enter the value ";
            cin>>newnode->data;
            newnode->next = NULL;

            if(head == NULL){
                head = newnode;
            }
            else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            }
        }

        void insertAtBegin(){
            node *temp = new node();
            cout<<"enter the value";
            cin>>temp->data;
            temp->next = head;
            head = temp;
        }
        void insertAtPosition(){
            int p = 0;
            node *newnode = new node();
            node *temp = head;
            cout<<"enter the position: ";
            cin>>p;
            cout<<"enter the value: ";
            cin>>newnode->data;
            if(p == 1){
                newnode->next = head;
                head = newnode;
                return;
            }
            for(int i = 1;i < p-1 ;i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        void deleteAtBegin(){
            if(head == NULL)
                return;
            node *temp = head;
            head = temp->next;
        }

        void deleteAtEnd(){

            if(head->next == NULL){
                head = NULL;
                return;
                }
            node *temp = head;
            node *prev = NULL;
            while(temp ->next != NULL){
                prev = temp;
                temp =temp->next;
            }
            prev->next = NULL;
            cout<<"deleted";
        }

        void deleteAtPosition(){
            int p;
            cout<<"enter the position: ";
            cin>>p;
            if(p == 1){
                head = head->next;
                return;
             }
             node* temp = head;
             node* prev = NULL;
            for(int i = 1; i < p; i++){
                prev = temp;
                temp = temp->next;
            }

            prev->next = temp->next;
            
        }

        void display(){
            node *temp = head;
            while(temp != NULL){
                cout<< temp->data <<endl;
                temp = temp->next;
            }
        }
};
int main() {
    LinkedList obj;
    int c;
   
    do{
        cout<<"1.insertAtEnd"<<endl<<"2.insertAtBegin"<<endl<<"3.deleteAtEnd"<<endl<<"4.deleteAtBegin"<<endl<<"5.deleteAtPosition"<<endl<<"6.insertAtPosition"<<endl<<"7.display"<<endl<<"8.exit";
        cout<<endl<<"enter your choice:";
        cin>>c;
    switch(c){
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
        default:
            cout<<"exited";
        break;
    }
    }while(c != 8);
    return 0;
}