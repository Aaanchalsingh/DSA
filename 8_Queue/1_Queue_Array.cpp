// All QUEUE operation using Array
#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int *s;
    int front;
    int rear;
    int size;
    Queue()
    {
        size = 7;
        front = -1;
        rear = -1;
        s = new int[size];
    }
    void ENqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue OVERFLOW\n";
        }
        else
        {
            s[++rear] = x;
        }
    }
    void Dequeue()
    {
        if (front == rear)
            cout << "Queue UNDERFLOW\n";
        else
            front++;
    }
    int isempty()
    {
        if (front == rear)
            return 1;
        else
            return 0;
    }
    int isfull()
    {
        if (rear == size - 1)
            return 1;
        else
            return 0;
    }
    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue p;
    p.ENqueue(1);
    p.ENqueue(4);
    p.ENqueue(4);
    p.ENqueue(2);
    p.ENqueue(1);
    p.ENqueue(5);
    p.display();
    p.Dequeue();
    p.Dequeue();
    p.Dequeue();
    p.Dequeue();
    p.display();
    cout << p.isfull() << "\n";
    cout << p.isempty() << "\n";
    return 0;
}