#include<iostream>
using namespace std;


class node{
    public:
        int data;
        node* left;
        node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class tree{
    public:
        node *root;
    tree(){
        root = NULL;
    }

    void insert(){
        root = new node(10);
        root->left = new node(20);
        root->right = new node(30);
        root->left->left = new node(40);
        root->left->right = new node(50);
        root->right->left = new node(60);
        root->right->right = new node(70);
    }

    void inorder(node *temp){
        if(temp == NULL){
            return;
        }
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }

    void preorder(node *temp){
        if(temp == NULL){
            return;
        }

        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(node *temp){
        if(temp == NULL){
            return;
        }

        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }

    void levelOrder(node *temp){
        if (temp == NULL)
            return;
        

        int f = 0, r = 0;
        node *q[100];
         q[r++] = temp;
        while (f < r)
        {
            temp = q[f++];

            cout<<temp->data<<" ";
            
            if(temp->left != NULL)
            {
                q[r++] = temp->left;
            }

            if (temp->right != NULL)
            {
                q[r++] = temp->right;
            }
            
        }
        
    }

};

int main(){ 

    tree obj;
    obj.insert();
    cout<<"IN ORDER"<<endl;
    obj.inorder(obj.root);
    cout<<endl<<"PRE ORDER"<<endl;
    obj.preorder(obj.root);
    cout<<endl<<"POST ORDER"<<endl;
    obj.postorder(obj.root);
    cout<<endl<<"LEVEL ORDER"<<endl;
    obj.levelOrder(obj.root);
    return 0;
}
