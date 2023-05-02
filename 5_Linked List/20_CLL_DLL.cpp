// CIRCULAR DOUBLY LINKED LIST
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node() {}
    node(int data) { this->data = data; }
} *head = NULL;
void display()
{
    node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}
void creation(int *A, int n)
{
    node *t, *last = NULL;
    head = new node(A[0]);
    head->next = head;
    head->prev = head;
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
void insert(int x, int loc)
{
    node *ptr = new node(x);
    node *last = NULL;
    node *temp = head;

    if (loc == 0)
    {
        do
        {
            last = temp;
            temp = temp->next;
        } while (temp != head);
        ptr->next = head;
        ptr->prev = last;
        last->next = ptr;
        head->prev = ptr;
        head = ptr;
    }

    else
    {
        node *temp = new node;
        temp = head;

        int i = 0;
        do
        {
            temp = temp->next;
            i++;
        } while (i < (loc - 1) && (temp != head));
        if (temp != head)
        {
            ptr->next = temp->next;
            ptr->prev = temp;
            if (temp->next)
                temp->next->prev = ptr;
            temp->next = ptr;
        }
        else
            cout << "ENTER CORRECT LOCATION :)\n";
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    creation(A, 10);
    insert(5, 0);
    display();
    return 0;
}