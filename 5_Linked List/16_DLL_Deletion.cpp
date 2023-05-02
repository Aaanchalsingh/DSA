#include <bits/stdc++.h>
using namespace std;
int size = 0;
class node
{
public:
    int data;
    node *next;
    node *prev;
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
    head->prev = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        t->next = last->next;
        t->prev = last;
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
void deletion(int loc)
{
    node *ptr = head;

    if (loc == 1)
    {
        head = head->next;
        delete ptr;
        size--;
    }
    else
    {
        for (int i = 0; i < (loc) && (ptr != NULL); i++)
        {
            ptr = ptr->next;
        }
        if (ptr)
        {
            ptr->prev->next = ptr->next;
            // if (ptr->next)
            //     ptr->next->prev = ptr->prev;
            size--;
            delete ptr;
        }
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, sizeof(A) / 4);
    deletion(7);
    display(size);
    return 0;
}