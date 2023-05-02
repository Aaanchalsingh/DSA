// All Stack operation using Array
#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int top;
    int *s;
    Stack()
    {
        size = 5;
        top = -1;
        s = new int[size];
    }
};
void push(Stack *p, int x)
{
    if (p->top >= p->size)
        cout << "STACK OVERFLOW\n";
    else
    {
        p->top++;
        p->s[p->top] = x;
    }
}
void pop(Stack *p)
{

    if (p->top == -1)
        cout << "STACK UNDERFLOW\n";
    else
    {
        cout << "\nDELETED : " << p->s[p->top];
        p->top--;
    }
}
int stacktop(Stack *p)
{
    if ((p->top > (p->size - 1)) || (p->top == -1))
        return -1;
    else
        return p->s[p->top];
}
int peek(Stack *t, int index)
{
    if ((index <= t->size - 1) && (index >= 0))
        return t->s[index];
    return -1;
}
int isempty(Stack *p)
{
    if (p->top == -1)
        return 1;
    else
        return 0;
}
int isfull(Stack *p)
{

    if (p->top > p->size - 1)
        return 1;
    else
        return 0;
}
void display(Stack *p)
{

    for (int i = 0; i <= p->top; i++)
    {
        cout << p->s[i] << " ";
    }
    cout << endl;
}
int main()
{
    Stack *q = new Stack;
    push(q, 1);
    push(q, 4);
    push(q, 4);
    push(q, 2);
    push(q, 1);
    push(q, 4);
    cout << "\nPEEK : " << peek(q, 3) << "\n";
    display(q);
    pop(q);
    pop(q);
    display(q);
    cout << "\nTOP : " << stacktop(q) << "\n";
    cout << isfull(q) << "\n";
    cout << isempty(q) << "\n";

    return 0;
}