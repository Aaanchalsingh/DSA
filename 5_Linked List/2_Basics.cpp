// PROGRAM TO COUNT,SUM & MAXIMUM
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
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
void count_sum_max(int n)
{
    int count = n, sum = 0, max = 0;
    node *ptr = new node;
    ptr = head;
    while (ptr)
    {
        sum += ptr->data;
        if (max < ptr->data)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    cout << "\nSUM : " << sum << "\ncount : " << count << "\nMAX : " << max << endl;
}
int Rsum(node *ptr)
{
    if (!ptr)
        return 0;
    return Rsum(ptr->next) + ptr->data;
}
int Rmax(node *ptr)
{
    int static max = 0;
    if (!ptr)
        return max;
    else
    {
        if (max < ptr->data)
            max = ptr->data;
        Rmax(ptr->next);
    }
}
void linear_search(int key)
{
    node *ptr = new node;
    ptr = head;
    while (ptr)
    {
        if (key == ptr->data)
        {
            cout << "FOUND ";
            return;
        }
        ptr = ptr->next;
    }
    cout << "NOT FOUND ";
}
bool Rlinear_search(node *ptr, int key)
{
    if (!ptr)
        return false;
    else
    {
        if (key == ptr->data)
            return true;
        Rlinear_search(ptr->next, key);
    }
}
int main()
{
    int A[] = {1, 4, 4, 2, 1, 4, 3, 2};
    creation(A, 8);
    display(8);
    count_sum_max(8);
    node *ptr = new node;
    ptr = head;
    cout << "RSUM : " << Rsum(ptr) << endl;
    cout << "RMAX : " << Rmax(ptr) << endl;
    cout << Rlinear_search(ptr, 4);
    return 0;
}
//%TIPS FROM FUTURE BELOW
//@BEFORE MOVING FORWARD GO REVISE RECURSION FIRST AND THEN COMEBACK