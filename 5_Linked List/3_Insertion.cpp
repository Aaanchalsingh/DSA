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
    for (int i = 0; i < size; i++)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
node *insert(int x, int loc)
{
    node *ptr = new node(x);
    size++;
    if (loc == 1)
    {
        ptr->next = head;
        head = ptr;
        return ptr;
    }
    else
    {
        node *temp = new node;
        temp = head;
        for (int i = 0; i < (loc - 2) && (temp != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp)
        {
            ptr->next = temp->next;
            temp->next = ptr;
            return head;
        }
        cout << "ENTER CORRECT LOCATION :)\n";
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
        ptr->next = NULL;
        temp->next = ptr;
    }
}
void insertSorted(int x)
{
    node *ptr = new node(x);
    node *temp = new node;
    node *last = new node;
    temp = last = head;
    for (int i = 0; i < size; i++)
    {
        if (x > temp->data)
        {
            last = temp;
            temp = temp->next;
        }
    }
    ptr->next = temp;
    last->next = ptr;
}

int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, sizeof(A) / 4);
    head = insert(5, 2);
    insert(5, 2);
    insert(5, 2);
    // insertLast(5);
    // insertLast(6);
    // insertLast(7);
    // insertLast(8);
    // // insertSorted(5);
    display(size);
    return 0;
}
//%TIPS FROM FUTURE BELOW
//@ALWAYS REMEMBER FOR INSERTION LINKING IS DONE KEEPING IN MIND THAT WE NEVER LOSE A DATA