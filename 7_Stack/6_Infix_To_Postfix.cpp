// Check if Parenthesis is balanced or not using Linked List
#include <bits/stdc++.h>
// #pragma GCC diagnostic ignored "-Wwrite-strings"
// TO REMOVE WARNING OF CHAR* TO STRING
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
int pop()
{
    Node *t = top;
    if (t == NULL)
    {
        cout << "Node UNDERFLOW\n";
    }
    else
    {
        int x = top->data;
        top = top->next;
        delete[] t;
        return x;
    }
}
int Stacktop()
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
bool isoperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
    {
        return true;
    }
    else
        return false;
}
int precedence(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else
        return 0;
}
// const is written to avoid ISO gcc forbids converting char*to string
const char *Postfix(const char *infix)
{
    char *postfix = new char[sizeof(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(Stacktop()))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (!isempty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    const char *infix = "a+b-c/d*e";
    cout << Postfix(infix);

    return 0;
}