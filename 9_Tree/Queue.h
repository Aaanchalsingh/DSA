#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
    }
};
class Queue
{
public:
    node **s;
    int front;
    int rear;
    int size;
    Queue()
    {
        size = 12;
        front = -1;
        rear = -1;
        s = new node *[size];
    }
    void ENqueue(node *x)
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
    int isempty()
    {
        if (front == rear)
            return 1;
        else
            return 0;
    }
    node *Dequeue()
    {
        if (isempty())
            cout << "Queue UNDERFLOW\n";
        else
        {
            node *x = s[++front];
            return x;
        }
    }

} q,r;
