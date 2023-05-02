// CIRCULAR LINKED LIST
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
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
void reverse_Link()
{
    node *ptr = head;
    node *temp;
    while (ptr != NULL)
    {
        temp = ptr->next;      // SIMPLY TO REVERSE THE DLL WE REVERSED THE PTR->NEXT AND PTR->PREV POINTERS
        ptr->next = ptr->prev; // AND AS WE KNOW THAT NEXT AND PREV  POINTERS ARE REVERSED WE NEED
        ptr = ptr->prev;//NEXT POINTER BUT WE CAN REPLACE IT WITH PREV POINTER
        if (ptr->next == NULL)//JUST USING THE ALGORITHM TO SWAP
        {
            ptr->next = ptr->prev;
            ptr->prev = NULL;
            head = ptr;
            break;
        }
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, 8);
    reverse_Link();
    display(8);

    return 0;
}