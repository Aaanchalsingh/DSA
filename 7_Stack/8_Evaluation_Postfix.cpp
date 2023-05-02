// TO EVALUATE POSTFIX EXPRESSION
#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
    Node() {}
} *top = NULL;
void push(int x)
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
bool isoperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*' || a == '(' || a == ')' || a == '^')
    {
        return true;
    }
    else
        return false;
}
int evaluation(string pfix)
{
    int i = 0, x1, x2, j = 0;
    while (pfix[i] != '\0')
    {
        if (!isoperator(pfix[i]))
        {
            push(pfix[i++] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (pfix[i++])
            {
            case '+':
                j = x1 + x2;
                push(j);
                break;
            case '-':
                j = x1 - x2;
                push(j);
                break;
            case '*':
                j = x1 * x2;
                push(j);
                break;
            case '/':
                j = x1 / x2;
                push(j);
                break;
            case '^':
                j = x1 ^ x2;
                push(j);
                break;
            default:
                break;
            }
        }
    }
    return top->data;
}
int main()
{
    string infix = "1532+/7+2*";
    cout << "RESULT = " << evaluation(infix);
    return 0;
}