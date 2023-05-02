// DELETION
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
void creation(int *A, int n) // no need to understand this right now
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
int deletion(int loc)
{
    node *ptr = NULL;
    node *p = head;

    if (loc == 1)
    {
        head = head->next;
        size--;
    }
    else
    {
        for (int i = 0; i < (loc - 1) && (p != NULL); i++)
        {
            ptr = p;
            p = p->next;
        }
        if (p)
        {
            ptr->next = p->next;
            size--;
            delete p;
        }
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, 8);
    // deletion(8);
    // deletion(1);
    deletion(5);
    display(7);
    return 0;
}