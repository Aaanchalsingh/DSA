#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
    }
};
void SortedInsert(Node **H, int x)
{
    Node *t, *q = NULL, *p = *H;

    t = new Node(x);
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
Node *Search(Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int hash_(int key)
{
    return key % 10;
}
void Insert(Node *H[], int key)
{
    int index = hash_(key);
    SortedInsert(&H[index], key);
}
int main()
{
    Node *HT[10];
    Node *temp;

    for (int i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = Search(HT[hash_(21)], 21);

    cout << temp->data;

    return 0;
}