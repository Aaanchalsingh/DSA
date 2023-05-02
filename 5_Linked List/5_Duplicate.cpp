// REMOVE Consecutive DUPLICATES
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
void duplicates()
{
    node *p = head;
    node *ptr = head->next;
    while (ptr)
    {
        if ((p->data) == (ptr->data))
        {
            p->next = ptr->next;
            delete ptr;
            ptr = p->next;
            size--;
        }
        else
        {
            p = ptr;
            ptr = ptr->next;
        }
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, 8);
    duplicates();
    display(size);
    return 0;
}