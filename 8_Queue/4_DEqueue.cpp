// INTRODUCTION TO DEQUEUE
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int *s;
    int front;
    int rear;
    int size;
    node()
    {
        size = 7;
        front = -1;
        rear = -1;
        s = new int[size];
    }
    void ENqueue_Last(int x)
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
    void ENqueue_Front(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue OVERFLOW\n";
        }
        else
        {
            if (front != -1)
            {
                s[front] = x;
                front--;
            }
            else
            {
                cout << "NOT POSSIBLE\n";
            }
        }
    }
    void Dequeue_Front()
    {
        if (front == rear)
            cout << "Queue UNDERFLOW\n";
        else
            front++;
    }
    void Dequeue_Last()
    {
        if (front == rear)
            cout << "Queue UNDERFLOW\n";
        else
            rear--;
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
    node p;
    p.ENqueue_Last(1);
    p.ENqueue_Last(2);
    p.ENqueue_Last(3);
    p.ENqueue_Last(4);
    p.display();
    p.Dequeue_Front();
    p.Dequeue_Front();
    p.display();
    p.ENqueue_Front(5);
    p.ENqueue_Front(6);
    p.ENqueue_Front(7);
    p.display();
    p.Dequeue_Last();
    p.Dequeue_Last();
    p.display();
    cout << p.isfull() << "\n";
    cout << p.isempty() << "\n";
    return 0;
}