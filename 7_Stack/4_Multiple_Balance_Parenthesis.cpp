// Check if Multiple Parenthesis is balanced or not using Linked List
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
bool check(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return true;
    }
    else if (a == '{' && b == '}')
    {
        return true;
    }
    else if (a == '[' && b == ']')
    {
        return true;
    }
    else
        return false;
}
bool isbalance(string s)
{
    Node *p = top;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (isempty())
                return false;
            if (check(top->data, s[i]))
            {
                pop();
            }
        }
    }
    return isempty() ? true : false;
}
int main()
{
    int t;
    cin >> t;
    int n[100];
    string s;
    int k = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        n[k++] = isbalance(s);
    }
    if (isbalance(s))
        cout << "BALANCED";
    else
        cout << "UNBALANCED";
    return 0;
}