// REVERSING LINKED LIST
//#1. MOVING ELEMENTS
//@2. REVERSING LINKS
#include <bits/stdc++.h>
using namespace std;
int size = 0;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        size++;
        this->data = data;
    }
    node() {}
} *head = NULL;
void creation(int *A, int n)
{
    node *t, *last;
    head = new node(A[0]);
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(int n)
{
    node *ptr = new node;
    ptr = head;
    for (int i = 0; i < n; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int Reverse()
{
    int A[11], i = 0;
    node *ptr = head;
    while (ptr)
    {
        A[i++] = ptr->data;
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr)
    {
        ptr->data = A[--i];
        ptr = ptr->next;
    }
}
void reverse_Link()
{
    node *p, *q, *r;
    q = r = NULL;
    p = head;
    while (p)
    {

        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void reverse_Recursion(node *p, node *q)
{
    if (p)
    {
        reverse_Recursion(p->next, p);
        p->next = q;
    }
    else
    {
        head = q;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    creation(A, 8);
    reverse_Recursion(head, NULL);
    display(size);
    return 0;
}