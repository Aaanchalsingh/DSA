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
void creation(int *A, int n)
{
    node *t, *last;
    head = new node(A[0]);
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(int n)
{
    node *ptr = new node;
    ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}
int deletion(int loc)
{
    node *ptr = NULL;
    node *p = head;

    if (loc == 1)
    {
        if (head == NULL)
        {
            delete head;
        }
        else
        {
            head = head->next;
            size--;
        }
    }
    else
    {
        int i = 0;
        do
        {
            ptr = p;
            p = p->next;
            i++;
        } while (i < (loc - 1) && (p != head));
        if (p != head)
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
    deletion(8);
    deletion(1);
    deletion(2);
    display(5);
    return 0;
}