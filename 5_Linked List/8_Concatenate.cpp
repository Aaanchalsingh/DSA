//#CONCATINATING TWO LINKED LIST
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
} *head = NULL, *second = NULL;
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
void Concatenate()
{
    node *ptr = new node;
    ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = second;
    // second = NULL;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    creationA(A, 8);
    int B[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creationB(B, 8);
    Concatenate();
    display(16);
    return 0;
}