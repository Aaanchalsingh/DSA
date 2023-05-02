// Check if Parenthesis is balanced or not using Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    char data;
    Node *next;
    Node(char data)
    {
        this->data = data;
    }
    Node() {}
} *top = NULL;
void push(char x)
{
    Node *t = new Node(x);
    if (t == NULL)
    {
        cout << "Node OVERFLOW\n";
    }
    else
    {
        t->next = top;
        top = t;
    }
}
void pop()
{
    Node *t = top;
    if (t == NULL)
    {
        cout << "Node UNDERFLOW\n";
    }
    else
    {
        top = top->next;
        delete[] t;
    }
}
int StackTop()
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
    Node *t = new Node;
    if (t == NULL)
        return 1;
    else
        return 0;
}
bool isbalance(char *s)
{
    Node *p = top;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            push(s[i]);
        else if (s[i] == ')')
        {
            if (isempty())
                return false;
            else
                pop();
        }
    }
    return isempty() ? true : false;
}
int main()
{
    char str[] = "((((a+b)*()c+d)))";
    if (isbalance(str))
        cout << "BALANCED";
    else
        cout << "UNBALANCED";
    return 0;
}