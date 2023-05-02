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
void insert(int x, int loc)
{
    node *ptr = new node(x);
    node *temp = new node;
    temp = head;
    node *op = new node;
    op = head;
    if (loc == 0)
    {
        if (temp == NULL)
        {
            temp = ptr;
            ptr->next = temp;
        }
        else
        {
            while (op->next != temp)
            {
                op = op->next;
            }
            op->next = ptr;
            ptr->next = temp;
            head = ptr;
        }
    }
    else
    {
        int i = 0;
        do
        {
            temp = temp->next;
            i++;
        } while (i < loc - 1 && temp != head);
        ptr->next = temp->next;
        if (temp == head)
            temp = ptr;
        else
            temp->next = ptr;
    }
}
void insertLast(int x)
{
    node *ptr = new node(x);
    node *temp = new node;
    temp = head;
    if (!temp)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        for (int i = 0; i < size - 2; i++)
        {
            temp = temp->next;
        }
        ptr->next = head;
        temp->next = ptr;
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, sizeof(A) / 4);
    insert(5, 8);
    // insertLast(5);
    // insertLast(6);
    // insertLast(7);
    // insertLast(8);
    display(size);
    return 0;
}