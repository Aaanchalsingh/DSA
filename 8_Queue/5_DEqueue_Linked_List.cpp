// DEQUEUE USING LINKED LIST
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
    }
    node() {}
} *front = NULL, *rear = NULL;
void ENqueue(int x)
{
    node *t = new node(x);
    if (t == NULL)
    {
        cout << "Queue OVERFLOW\n";
    }
    else
    {
        t->next = NULL;
        if (rear == NULL)
        {
            rear = front = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
void ENqueuef(int x)
{
    node *t = new node(x);
    if (t == NULL)
    {
        cout << "Queue OVERFLOW\n";
    }
    else
    {
        t->next = front;
        front = t;
    }
}
void Dequeue()
{
    node *t = front;
    if (front == rear)
    {
        cout << "Queue UNDERFLOW\n";
    }
    else
    {
        // cout << "DELETED : " << t->data;
        front = front->next;
        delete[] t;
    }
}
void Dequeuer()
{
    node *t = front;
    if (front == rear)
    {
        cout << "Queue UNDERFLOW\n";
    }
    else
    {
        // cout << "DELETED : " << t->data;
        while (t->next != rear)
        {
            t = t->next;
        }
        rear = t;
        t = t->next;
        delete[] t;
    }
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
    node *t = new node;
    if (t == NULL)
        return 1;
    else
        return 0;
}
void display()
{
    cout << endl;
    node *t = front;
    if (front!=rear)
    {
        do

        {

            cout << t->data << " ";
            t = t->next;

        } while (t != rear);
        cout << t->data << " ";
        cout << endl;
    }
}
int main()
{
    ENqueue(1);
    ENqueue(2);
    ENqueue(3);
    display();
    ENqueuef(4);
    ENqueuef(5);
    ENqueuef(6);
    display();
    ENqueue(8);
    ENqueue(9);
    ENqueue(10);
    display();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    display();
    Dequeuer();
    Dequeuer();
    Dequeuer();
    Dequeuer();
    Dequeuer();
    Dequeuer();
    display();
    // cout << "\nPEEK : " << peek(2) << "\n";
    cout << isfull() << "\n";
    cout << isempty() << "\n";
    return 0;
}