// INSERTION SORT using linked list
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data) { this->data = data; }
    node() {}
} *head = NULL;
void creating_linkedlist(int A[], int n)
{
    head = new node(A[0]);
    head->next = NULL;
    node *t, *last = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void Insertion_Sort(node *p)
{
    node *q = head, *t = NULL;
    int val;
    while (p)
    {
        p = p->next;
        while (q != p)
        {
            if (p->data < q->data)
            {
                t = new node(p->data);
                t->next = q->next;
                q->next = t;
            }
            q = q->next;
        }
    }
    //   int j = 0, val = 0;
    // for (int i = 1; i < n; i++)
    // {               // val=20;
    //     j = i - 1;  //  0, 20, 5, 35, 10, 15, 40, 30
    //     val = A[i]; // j
    //     while ((j >= 0) && (val < A[j]))
    //     {
    //         A[j + 1] = A[j];
    //         j--;
    //     }
    //     A[j + 1] = val;
    // }
}
int main()
{
    int A[] = {0, 20, 5, 35, 10, 15, 40, 30};
    creating_linkedlist(A, sizeof(A) / 4);
    Insertion_Sort(head);
    display(head);

    return 0;
}
