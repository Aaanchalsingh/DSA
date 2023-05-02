// MIDDLE ELEMENT IN THE LINKED LIST
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

} *head = NULL, o, *second = NULL;
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
void creation2(int *A, int n)
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
void Intersection(node *p, node *q)
{

    int A[12], B[12];
    int i = 0, j = 0;
    while (p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    while (q)
    {
        B[j] = q->data;
        q = q->next;
        j++;
    }
    int k = 0;
    while (p && q)
    {
        if (A[k] == B[k])
        {
            i--;
            j--;
        }
        else
        {
            cout << A[k];
        }
    }
}
int main()
{
    int Arr[] = {1, 4, 4, 2};
    creation(Arr, 4);
    int Ar[] = {1, 4, 3, 2};
    creation2(Arr, 4);
    Intersection(head, second);

    return 0;
}