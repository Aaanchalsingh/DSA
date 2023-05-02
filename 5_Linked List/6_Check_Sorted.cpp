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
int Check_Sorted()
{
    node *p = head;
    node *ptr = head->next;
    while (ptr)
    {
        if ((p->data) <= (ptr->data))
        {
            p = ptr;
            ptr = ptr->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int A[] = {1,2,3,4,5,6,7,8};
    creation(A, 8);
    cout<<Check_Sorted()<<endl;
    display(size);
    return 0;
}