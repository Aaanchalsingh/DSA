//#MERGING TWO SORTED LINKED LIST
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
} *head = NULL, *second = NULL, *third = NULL;
void creationA(int *A, int n)
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
void creationB(int *A, int n)
{
    node *t, *last;
    second = new node(A[0]);
    second->next = NULL;
    last = second;
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
int Loop(node *p)
{
    node *q = head;
    do
    {
        p = p->next;
        q = q->next;
        if (q)
            q = q->next;
        if (q == p)
            return 1;

    } while (p && q);
    return 0;
}
int main()
{
    node *t1, *t2;
    int A[] = {2, 4, 6, 8, 10, 12, 16};
    creationA(A, 7);
    t1 = head->next->next->next;
    t2 = head->next->next->next->next->next;
    t2->next = t1;
    cout << Loop(head);
    return 0;
}