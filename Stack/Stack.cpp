#include <iostream>
using namespace std;

class Stack
{
public:
    int arr[100] = {0}, i = -1;

    void push()
    {
        cout << "enter the value:" << endl;
        i++;
        cin >> arr[i];
    }
    void pop()
    {
        cout << "value got popped" << endl;
        i--;
    }
    void top()
    {
        cout << "top value: " << arr[i] << endl;
    }

    void display()
    {
        for (int ii = 0; ii <= i; ii++)
        {
            cout << arr[ii] << endl;
        }
    }
    void isEmpty()
    {
        if (i < 0)
            cout << "stack is empty" << endl;
        else
            cout << "STACK IS NOT EMPTY" << endl;
    }
};

int main()
{
    Stack obj;
    int c;
    do
    {
        cout << "1.push" << endl
             << "2.pop" << endl
             << "3.display" << endl
             << "4.top element" << endl
             << "5.isEmpty" << endl
             << "6.exit" << endl;
        cout << endl
             << "enter your choice:";
        cin >> c;
        switch (c)
        {
        case 1:
            obj.push();
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            obj.top();
            break;
        case 5:
            obj.isEmpty();
            break;
        case 6:
            cout << "exited successfully" << endl;
            break;
        default:
            cout << "enter a valid option" << endl;
            break;
        }
    } while (c != 6);
    return 0;
}