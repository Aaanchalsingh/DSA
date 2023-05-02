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

} *head = NULL, o;
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
void middle()
{
    node *p, *q;
    p = q = head;
    while (q)
    {

        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    cout << p->data;
}
void middle2()//USING ARRAY APPROACH
{
    node *p = head;
    int A[12];
    int i = 0;
    while (p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    cout << A[(i - 1) / 2];
}
int main()
{
    int Arr[] = {1, 4, 4, 3, 2};
    creation(Arr, 5);
    middle2();
    middle();
    return 0;
}