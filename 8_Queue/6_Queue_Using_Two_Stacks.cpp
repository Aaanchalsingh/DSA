// QUEUE USING TWO STACKS
#include <bits/stdc++.h>
using namespace std;
int total = 0;
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
};
class s1
{
public:
    node *top = NULL;
    void push(int x)
    {
        node *t = new node(x);
        if (t == NULL)
            cout << "STACK OVERFLOW\n";
        else
        {
            t->next = top;
            top = t;
        }
        total++;
    }
    int pop()
    {
        node *t = top;
        if (t == NULL)
        {
            cout << "STACK UNDERFLOW\n";
        }
        else
        {
            int n = t->data;
            top = top->next;
            delete[] t;
            return n;
        }
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
} p;
class s2
{
public:
    node *top = NULL;
    void push(int x)
    {
        node *t = new node(x);
        if (t == NULL)
            cout << "STACK OVERFLOW\n";
        else
        {
            t->next = top;
            top = t;
        }
    }
    int pop()
    {
        node *t = top;
        if (t == NULL)
        {
            cout << "STACK UNDERFLOW\n";
        }
        else
        {
            int n = t->data;
            top = top->next;
            delete[] t;
            return n;
        }
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
} q;

int main()
{
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);
    p.push(6);
    p.push(2);
    p.push(3);
    p.push(4);
    p.display();

    for (int i = 0; i < total; i++)
    {
        q.push(p.pop());
    }
    q.display();

    return 0;
}