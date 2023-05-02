// All Stack operation using Linked List
#include <bits/stdc++.h>
using namespace std;
// BASIC STRUCTURE OF NODE CONTAINS DATA AND NEXT POINTER
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
}; // BASIC STRUCTURE OF STACK CONTAINS TOP POINTER AND SIZE
// SINCE STACK CLASS IS USED OVERHERE AS A SLEEPING PARTNER SO WE WILL LEAVE IT FROM NEXT PROGRAM
class Stack
{
public:
    node *top = NULL;
    void push(int x)
    {
        node *t = new node(x);
        if (t == NULL)
        {
            cout << "STACK OVERFLOW\n";
        }
        else
        {
            t->next = top;
            top = t;
        }
    }
    void pop()
    {
        node *t = top;
        if (t == NULL)
        {
            cout << "STACK UNDERFLOW\n";
        }
        else
        {
            cout << "\nDELETED : " << t->data;
            top = top->next;
            delete[] t;
        }
    }
    int stacktop()
    {
        if (top)
        {
            return top->data;
        }
        else
            return -1;
    }
    int isempty()
    {
        if (!top)
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
        node *t = top;
        for (int i = 0; t != NULL; i++)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
    int peek(int index)
    {
        node *t = top;
        for (int i = 0; (i < index - 1) && (t != NULL); i++)
            t = t->next;
        if (t)
            return t->data;
        else
            return -1;
    }
};
int main()
{
    Stack q;
    q.push(1);
    q.push(4);
    q.push(4);
    q.push(2);
    q.push(1);
    q.push(4);
    cout << "\nPEEK : " << q.peek(9) << "\n";
    q.display();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();
    cout << "\nTOP : " << q.stacktop() << "\n";
    cout << q.isfull() << "\n";
    cout << q.isempty() << "\n";

    return 0;
}