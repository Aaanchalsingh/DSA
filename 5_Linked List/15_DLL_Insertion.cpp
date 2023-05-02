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
void insert(int x, int loc)
{
    node *ptr = new node(x);
    if (loc == 0)
    {
        ptr->prev = NULL;//MAKING HEAD POINTER FOR THE PROGRAM 
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        size++;
    }

    else
    {
        node *temp = new node;
        temp = head;
        for (int i = 0; i < (loc - 1) && (temp != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            ptr->next = temp->next;
            ptr->prev = temp;
            if (temp->next)
                temp->next->prev = ptr;
            temp->next = ptr;
            size++;
        }
        else
            cout << "ENTER CORRECT LOCATION :)\n";
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, sizeof(A) / 4);
    insert(5, 1);
    display(size);
    return 0;
}