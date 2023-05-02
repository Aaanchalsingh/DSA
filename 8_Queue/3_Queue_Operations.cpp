// All QUEUE operation using Linked List
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
void Dequeue()
{
    node *t = front;
    if (front == rear)
    {
        cout << "Queue UNDERFLOW\n";
    }
    else
    {
        cout << "\nDELETED : " << t->data;
        front = front->next;
        delete[] t;
    }
}
int last()
{
    if (rear)
    {
        return rear->data;
    }
    else
        return -1;
}
int first()
{
    if (front)
    {
        return front->data;
    }
    else
        return -1;
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
    node *t = front;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int peek(int index)
{
    node *t = front;
    for (int i = 0; (i < index - 1) && (t != NULL); i++)
        t = t->next;
    if (t)
        return t->data;
    else
        return -1;
}
int main()
{
    ENqueue(1);
    ENqueue(4);
    ENqueue(4);
    ENqueue(2);
    ENqueue(1);
    ENqueue(4);
    Dequeue();
    display();
    cout << "\nPEEK : " << peek(2) << "\n";
    display();
    cout << "\nFIRST : " << first() << "\n";
    cout << "\nLAST : " << last() << "\n";
    cout << isfull() << "\n";
    cout << isempty() << "\n";
    return 0;
}