#include <iostream>
using namespace std;

class Queue
{
public:
    int arr[100], r = -1, f = 0;
    void enqueue()
    {
        cout << "enter the value :";
        r++;
        cin >> arr[r];
    }
    void dequeue()
    {
        f++;
        cout << "element removed";
    }
    void front()
    {
        cout << "front element: " << arr[f];
    }
    void isEmpty()
    {
        if (f > r)
            cout << "Queue is empty";
        else
            cout << "Queue is not empty";
    }
    void display()
    {
        for (int i = f; i <= r; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    int c;
    Queue obj;
    do
    {
        cout << endl
             << "1.enqueue" << endl
             << "2.dequeue" << endl
             << "3.front" << endl
             << "4.isEmpty" << endl
             << "5.display" << endl
             << "6.exit" << endl;
        cout << endl
             << "enter choice:";
        cin >> c;
        switch (c)
        {
        case 1:
            obj.enqueue();
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.front();
            break;
        case 4:
            obj.isEmpty();
            break;
        case 5:
            obj.display();
            break;
        case 6:
            cout << "exited";
            break;
        default:
            cout << "enter an valid option";
            break;
        }
    } while (c != 6);
    return 0;
}